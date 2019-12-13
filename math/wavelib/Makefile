# $FreeBSD$

PORTNAME=	wavelib
DISTVERSION=	g20191022
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Wavelet Transform (DWT, SWT and MODWT)

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USES=		cmake dos2unix
DOS2UNIX_FILES=	auxiliary/CMakeLists.txt
USE_GITHUB=	yes
GH_ACCOUNT=	rafat
GH_TAGNAME=	cef10c1
USE_LDCONFIG=	yes

CMAKE_OFF=	BUILD_UT

PLIST_FILES=	include/wavelib/waux.h \
		include/wavelib/wauxlib.h \
		include/wavelib/wavelib.h \
		lib/libwavelib.so

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/Bin/Release/libwavelib.so ${STAGEDIR}${PREFIX}/lib
	${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/header/wavelib.h ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/header/wauxlib.h ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/auxiliary/waux.h ${STAGEDIR}${PREFIX}/include/${PORTNAME}

.include <bsd.port.mk>
