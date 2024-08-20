PORTNAME=	koboldcpp
DISTVERSIONPREFIX=	v
DISTVERSION=	1.73
CATEGORIES=	misc # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simple way to run GGML and GGUF AI models with a KoboldAI WebUI
WWW=		https://github.com/lostruins/koboldcpp

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libopenblas.so:math/openblas \
		libvulkan.so:graphics/vulkan-loader

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}customtkinter>0:x11-toolkits/py-customtkinter@${PY_FLAVOR}

USES=		gmake localbase:ldflags python shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	LostRuins

SHEBANG_FILES=	koboldcpp.py

MAKE_ARGS=	LLAMA_OPENBLAS=1 LLAMA_VULKAN=1 LLAMA_PORTABLE=1 LDFLAGS="${LDFLAGS}"

ALL_TARGET=

do-install:
	# dir
	${MKDIR} ${STAGEDIR}${DATADIR}
	# prog
	${INSTALL_DATA} ${WRKSRC}/koboldcpp.py ${STAGEDIR}${DATADIR}/koboldcpp.py
	${CHMOD} +x ${STAGEDIR}${DATADIR}/koboldcpp.py
	${RLN} ${STAGEDIR}${DATADIR}/koboldcpp.py ${STAGEDIR}${PREFIX}/bin/koboldcpp
	# libraries
.for lib in koboldcpp_default.so koboldcpp_failsafe.so koboldcpp_noavx2.so \
	    koboldcpp_openblas.so koboldcpp_vulkan.so koboldcpp_vulkan_noavx2.so
	${INSTALL_LIB} ${WRKSRC}/${lib} ${STAGEDIR}${DATADIR}
.endfor
	# embd files
.for embd in klite.embd kcpp_docs.embd rwkv_vocab.embd rwkv_world_vocab.embd \
	     kcpp_sdui.embd taesd.embd taesd_xl.embd
	${INSTALL_DATA} ${WRKSRC}/${embd} ${STAGEDIR}${DATADIR}
.endfor

.include <bsd.port.mk>
