# Created by: Andrey Akhmichin <sepulkarium45@yahoo.com>
# $FreeBSD$

PORTNAME=	pidgin-skypeweb
PORTVERSION=	08222015
CATEGORIES=	net-im

MAINTAINER=	sepulkarium45@yahoo.com
COMMENT=	Plugin to use Skype chat from Pidgin(without Skype running)

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/gpl3.txt

BUILD_DEPENDS=	pidgin:${PORTSDIR}/net-im/pidgin
RUN_DEPENDS=	pidgin:${PORTSDIR}/net-im/pidgin
LIB_DEPENDS=	libjson-glib-1.0.so:${PORTSDIR}/devel/json-glib

USE_GITHUB=	yes
GH_ACCOUNT=	EionRobb
GH_PROJECT=	skype4pidgin
GH_TAGNAME=	08cbc21

USES=		gmake pkgconfig
USE_GNOME=	glib20
USE_LDCONFIG=	yes

CONFLICTS_INSTALL=	pidgin-skype-*
WRKSRC_SUBDIR=	skypeweb

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/purple-2
	${INSTALL_PROGRAM} ${WRKSRC}/libskypeweb.so ${STAGEDIR}${PREFIX}/lib/purple-2
	${MKDIR} ${STAGEDIR}${PREFIX}/share/pixmaps/pidgin/emotes/skype
	${INSTALL_DATA} ${WRKSRC}/theme ${STAGEDIR}${PREFIX}/share/pixmaps/pidgin/emotes/skype
.for i in 16 22 48
	${MKDIR} ${STAGEDIR}${PREFIX}/share/pixmaps/pidgin/protocols/${i}
	${INSTALL_DATA} ${WRKSRC}/icons/${i}/skypeout.png \
		${WRKSRC}/icons/${i}/skype.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/pidgin/protocols/${i}/
.endfor

.include <bsd.port.mk>
