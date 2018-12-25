# $FreeBSD$

PORTNAME=	Bento4
PORTVERSION=	1.5.1
DISTVERSIONPREFIX=v
DISTVERSIONSUFFIX=-624
CATEGORIES=	multimedia devel

MAINTAINER=	mmokhi@FreeBSD.org
COMMENT=	Full-featured MP4 format and MPEG DASH library and tools

LICENSE=	GPLv2

BROKEN_aarch64=		fails to compile: Ap4AesBlockCipher.cpp:93:4: AP4_PLATFORM_BYTE_ORDER is not set

USES=		cmake:noninja

USE_GITHUB=	yes
GH_ACCOUNT=	axiomatic-systems

CMAKE_BUILD_TYPE=	Release
INSTALL_TARGET=		do-install

do-install:
.	for prog in aac2mp4 mp42aac mp42hls mp42ts mp4compact mp4dcfpackager \
	    mp4decrypt mp4diff mp4dump mp4edit mp4encrypt mp4extract mp4fragment \
	    mp4iframeindex mp4info mp4mux mp4split mp4tag
		${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/${prog} ${STAGEDIR}${PREFIX}/bin
.	endfor
	${INSTALL_DATA} ${INSTALL_WRKSRC}/libap4.a ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
