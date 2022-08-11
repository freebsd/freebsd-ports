PORTNAME=	mjpg-streamer
PORTVERSION=	g2021081601
PORTEPOCH=	1
CATEGORIES=	multimedia net

MAINTAINER=	swills@FreeBSD.org
COMMENT=	HTTP video streaming daemon

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev.h:multimedia/v4l_compat

USES=		cmake jpeg localbase

USE_GITHUB=	yes
GH_ACCOUNT=	jacksonliam
GH_TAGNAME=	310b29f4a94c46652b20c4b7b6e5cf24e532af39

WRKSRC_SUBDIR=	mjpg-streamer-experimental

USE_RC_SUBR=	mjpg_streamer
SUB_FILES+=	pkg-message

PORTSCOUT=	skipv:1.0.0

post-build:
	cd ${WRKSRC}/plugins/input_testpicture && \
		${SETENV} ${MAKE_ENV} make

post-install:
	${INSTALL_LIB} ${WRKSRC}/plugins/input_testpicture/input_testpicture.so ${STAGEDIR}${PREFIX}/lib/${PORTNAME}

.include <bsd.port.mk>
