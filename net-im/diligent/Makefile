# Created by: Kris Moore <kmoore@FreeBSD.org>

PORTNAME=	diligent
PORTVERSION=	0.2.7
PORTREVISION=	9
DISTVERSIONPREFIX=	v
CATEGORIES=	net-im

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Unofficial Qt Slack client

LICENSE=	LGPL3

BROKEN=		Unfetchable
DEPRECATED=	Abandoned upstream, users also confirms port to be non working
EXPIRATION_DATE=2022-03-31

USE_LDCONFIG=	yes
USE_QT=		core gui linguist network svg \
		webkit widgets x11extras buildtools_build
USE_GL=		gl
USES=		compiler:c++11-lang gl qmake qt:5

QMAKE_ARGS=	CONFIG+="configure"

USE_GITHUB=	yes
GH_ACCOUNT=	trueos

PLIST_FILES=	bin/diligent \
		share/applications/diligent.desktop \
		share/icons/diligent.png
SUB_FILES=	diligent.desktop

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/diligent ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKDIR}/${SUB_FILES} ${STAGEDIR}${PREFIX}/share/applications/
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons
	${INSTALL_DATA} ${WRKSRC}/images/png/Slack.png ${STAGEDIR}${PREFIX}/share/icons/diligent.png

.include <bsd.port.mk>
