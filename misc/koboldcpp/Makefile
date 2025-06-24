PORTNAME=	koboldcpp
DISTVERSIONPREFIX=	v
DISTVERSION=	1.94.1
CATEGORIES=	misc # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simple way to run GGML and GGUF AI models with a KoboldAI WebUI
WWW=		https://github.com/lostruins/koboldcpp

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.md

#BROKEN_armv7=	compilation fails, see https://github.com/LostRuins/koboldcpp/issues/1129
#BROKEN_i386=	compilation fails, see https://github.com/LostRuins/koboldcpp/issues/1129

FLAVORS=	default portable
FLAVOR?=	${FLAVORS:[1]}
portable_PKGNAMESUFFIX=	-portable

BUILD_DEPENDS=	glslc:graphics/shaderc
LIB_DEPENDS=	libopenblas.so:math/openblas \
		libvulkan.so:graphics/vulkan-loader

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}customtkinter>0:x11-toolkits/py-customtkinter@${PY_FLAVOR}

USES=		compiler:c++11-lang gmake localbase:ldflags python shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	LostRuins

SHEBANG_FILES=	koboldcpp.py

.if ${FLAVOR} == default
LIBS=	koboldcpp_default.so koboldcpp_vulkan.so
MAKE_ARGS=	PRESET_CFLAGS="${CFLAGS}" PRESET_CXXFLAGS="${CXXFLAGS}"
.endif
.if ${FLAVOR} == portable
MAKE_ARGS=	LLAMA_PORTABLE=1
LIBS=	koboldcpp_default.so koboldcpp_failsafe.so koboldcpp_noavx2.so \
	koboldcpp_vulkan.so koboldcpp_vulkan_noavx2.so
.endif

MAKE_ARGS+=	LLAMA_OPENBLAS=1 LLAMA_VULKAN=1 LDFLAGS="${LDFLAGS}"

ALL_TARGET=

PLIST_FILES=	${LIBS:S/^/%%DATADIR%%\//}

.if defined(WITH_DEBUG)
MAKE_ARGS+=	KCPP_DEBUG=1
.endif

post-patch:
	@${RM} ${WRKSRC}/glslc-linux
	@${LN} -s ${PREFIX}/bin/glslc ${WRKSRC}/glslc-linux

do-install:
	# dir
	${MKDIR} ${STAGEDIR}${DATADIR}
	# prog
	${INSTALL_DATA} ${WRKSRC}/koboldcpp.py ${STAGEDIR}${DATADIR}/koboldcpp.py
	${CHMOD} +x ${STAGEDIR}${DATADIR}/koboldcpp.py
	${RLN} ${STAGEDIR}${DATADIR}/koboldcpp.py ${STAGEDIR}${PREFIX}/bin/koboldcpp
	# libraries
.for lib in ${LIBS}
	${INSTALL_LIB} ${WRKSRC}/${lib} ${STAGEDIR}${DATADIR}
.endfor
	# embd files
.for embd in klite.embd kcpp_docs.embd rwkv_vocab.embd rwkv_world_vocab.embd \
	     kcpp_sdui.embd taesd.embd taesd_xl.embd
	${INSTALL_DATA} ${WRKSRC}/${embd} ${STAGEDIR}${DATADIR}
.endfor

.include <bsd.port.pre.mk>

.if ${ARCH} != amd64
IGNORE=	portable flavor isn't defined on ${ARCH} because it is based on AVX2, etc. (?)
.endif

.include <bsd.port.post.mk>
