PORTNAME=	Bento4
PORTVERSION=	1.6.0
PORTREVISION=	3
DISTVERSIONPREFIX=	v
DISTVERSIONSUFFIX=	-641
CATEGORIES=	multimedia devel

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Full-featured MP4 format and MPEG DASH library and tools
WWW=		https://www.bento4.com

LICENSE=	GPLv2

BROKEN_riscv64=	fails to compile: Ap4AesBlockCipher.cpp:93:4: AP4_PLATFORM_BYTE_ORDER is not set

RUN_DEPENDS=	bash:shells/bash

USES=		cmake:noninja cpe python shebangfix
CPE_VENDOR=	axiosys
USE_GITHUB=	yes
GH_ACCOUNT=	axiomatic-systems
SHEBANG_FILES=	Source/Python/*/*
SHEBANG_GLOB=	*.py *.sh

CMAKE_BUILD_TYPE=	Release
INSTALL_TARGET=	do-install

post-patch:
	@${REINPLACE_CMD} -e 's|python3|${PYTHON_CMD}|g' ${WRKSRC}/Source/Python/wrappers/*
	@${REINPLACE_CMD} -e 's|$$BASEDIR/..|${DATADIR}|g' ${WRKSRC}/Source/Python/wrappers/*

do-install:
. for prog in aac2mp4 mp42aac mp42hls mp42ts mp4compact mp4dcfpackager \
	mp4decrypt mp4diff mp4dump mp4edit mp4encrypt mp4extract mp4fragment \
	mp4iframeindex mp4info mp4mux mp4split mp4tag
		${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/${prog} ${STAGEDIR}${PREFIX}/bin
. endfor
	${INSTALL_DATA} ${INSTALL_WRKSRC}/libap4.a ${STAGEDIR}${PREFIX}/lib
	@${MKDIR} ${STAGEDIR}${DATADIR}/utils
	cd ${WRKSRC}/Source/Python/utils && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/utils
. for prog in mp4dash mp4dashclone mp4hls
	${INSTALL_SCRIPT} ${WRKSRC}/Source/Python/wrappers/${prog} ${STAGEDIR}${PREFIX}/bin
. endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/Bento4
	@${FIND} -s ${WRKSRC} -type f -name "*.h" -type f \
		-exec ${INSTALL_DATA} {} ${STAGEDIR}${PREFIX}/include/Bento4 ';'

.include <bsd.port.mk>
