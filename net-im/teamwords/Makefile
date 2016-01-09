# Created by: Kris Moore <kmoore@FreeBSD.org>
# $FreeBSD$

PORTNAME=	teamwords
PORTVERSION=	0.2.1
DISTVERSIONPREFIX=	v
CATEGORIES=	net-im

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	Unofficial Qt Slack client

LICENSE=	LGPL3

USE_LDCONFIG=	yes
USE_QT5=	core gui network svg linguist \
		buildtools x11extras
USES=		compiler:c++11-lang qmake tar:xz

QMAKE_ARGS=	CONFIG+="configure"

USE_GITHUB=	yes
GH_ACCOUNT=	MiT-Ufa
GH_PROJECT=	TeamWords
PLIST_FILES=	bin/teamwords \
		share/applications/teamwords.desktop \
		share/icons/teamwords.png
SUB_FILES=      teamwords.desktop

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/teamwords ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKDIR}/${SUB_FILES} ${STAGEDIR}${PREFIX}/share/applications/
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons
	${INSTALL_DATA} ${WRKSRC}/images/png/Slack.png ${STAGEDIR}${PREFIX}/share/icons/teamwords.png

.include <bsd.port.mk>
