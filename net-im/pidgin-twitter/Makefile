PORTNAME=	pidgin-twitter
PORTVERSION=	0.9.2
PORTREVISION=	10
CATEGORIES=	net-im
MASTER_SITES=	http://www.honeyplanet.jp/

MAINTAINER=	jun-g@daemonfreaks.com
COMMENT=	Pidgin plugin to help twitting via pidgin
WWW=		http://honeyplanet.jp/pidgin-twitter/

BUILD_DEPENDS=	pidgin:net-im/pidgin
RUN_DEPENDS=	pidgin:net-im/pidgin

USES=		gmake gnome pkgconfig
USE_GNOME=	glib20 libxml2
GNU_CONFIGURE=	yes

PLIST_FILES=	lib/pidgin/pidgin-twitter.so \
		${DATADIR_REL}/prefs.ui

post-patch:
	@${REINPLACE_CMD} -e 's|-Werror||g' ${WRKSRC}/Makefile.in

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/pidgin
	${INSTALL_LIB} ${WRKSRC}/pidgin-twitter.so ${STAGEDIR}${PREFIX}/lib/pidgin
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/prefs.ui ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
