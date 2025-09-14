PORTNAME=	qt-sudo
DISTVERSION=	2.2.0
CATEGORIES=	security
MASTER_SITES=	https://github.com/aarnt/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Clone of LXQt sudo tool without LXQt libs
WWW=		https://github.com/aarnt/qt-sudo

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gl qmake qt:6
USE_GL=		opengl
USE_QT=		base tools

PLIST_FILES=	bin/${PORTNAME}

post-patch:
	${REINPLACE_CMD} 's#/usr/local#${PREFIX}#' \
		${WRKSRC}/sudo.cpp

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
