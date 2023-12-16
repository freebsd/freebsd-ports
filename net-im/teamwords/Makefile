PORTNAME=	teamwords
PORTVERSION=	0.2.1
DISTVERSIONPREFIX=	v
PORTREVISION=	10
CATEGORIES=	net-im

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Unofficial Qt Slack client
WWW=		https://github.com/MiT-Ufa/TeamWords

LICENSE=	LGPL3

DEPRECATED=	Depends on deprecated www/qt5-webkit
EXPIRATION_DATE=	2023-12-31

USES=		compiler:c++11-lang gl qmake qt:5
USE_LDCONFIG=	yes
USE_QT=		core gui network webkit widgets buildtools:build
USE_GL=		gl

QMAKE_ARGS=	CONFIG+="configure"

USE_GITHUB=	yes
GH_ACCOUNT=	MiT-Ufa
GH_PROJECT=	TeamWords
PLIST_FILES=	bin/teamwords \
		share/applications/teamwords.desktop \
		share/icons/teamwords.png
SUB_FILES=	teamwords.desktop

OPTIONS_DEFINE=	WEBKITNOTIFY

WEBKITNOTIFY_DESC=	Use QtWebkit for notifications

post-patch-WEBKITNOTIFY-on:
	@${REINPLACE_CMD} 's|linux|unix|' \
		${WRKSRC}/plugins/qtwebkit/qtwebkit-plugins.pri

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/teamwords ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKDIR}/${SUB_FILES} ${STAGEDIR}${PREFIX}/share/applications/
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons
	${INSTALL_DATA} ${WRKSRC}/images/png/Slack.png ${STAGEDIR}${PREFIX}/share/icons/teamwords.png

.include <bsd.port.mk>
