PORTNAME=	octopkg
DISTVERSION=	0.4.1
CATEGORIES=	ports-mgmt
MASTER_SITES=	https://github.com/aarnt/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Graphical front-end to the FreeBSD pkg-ng package manager
WWW=		https://tintaescura.com/projects/octopkg/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	qt-sudo:security/qt-sudo

USES=		desktop-file-utils gl qmake qt:6
USE_GL=		opengl
USE_QT=		base tools

PLIST_FILES=	bin/${PORTNAME} \
		share/applications/${PORTNAME}.desktop \
		share/icons/octopi.png

post-patch:
	${REINPLACE_CMD} 's#/usr/local#${PREFIX}#' \
		${WRKSRC}/src/constants.h \
		${WRKSRC}/src/main.cpp \
		${WRKSRC}/src/strconstants.cpp

.include <bsd.port.mk>
