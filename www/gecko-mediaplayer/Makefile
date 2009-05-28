# New ports collection makefile for:	gecko-mediaplayer
# Date created:				14 March 2009
# Whom:					Alexander Logvinov <ports@logvinov.com>
#
# $FreeBSD$
#

PORTNAME=	gecko-mediaplayer
PORTVERSION=	0.9.5
CATEGORIES=	www multimedia gnome
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	avl@FreeBSD.org
COMMENT=	Multimedia browser plugin for Gecko based browsers

LIB_DEPENDS=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib
RUN_DEPENDS=	gnome-mplayer:${PORTSDIR}/multimedia/gnome-mplayer

OPTIONS=	GCONF	"Use Gconf to store preferences"	off \
		NOCACHE	"Disable caching of remote media to local storage"	off

GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
USE_GNOME=	glib20
USE_GECKO=	firefox mozilla seamonkey libxul
USE_WEBPLUGINS=	native
WEBPLUGINS_FILES=	${PORTNAME}-dvx.so ${PORTNAME}-qt.so ${PORTNAME}-rm.so \
				${PORTNAME}-wmp.so ${PORTNAME}.so
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

PORTDOCS=	README COPYING AUTHORS ChangeLog INSTALL NEWS javascript.txt

.include <bsd.port.pre.mk>

.if defined(WITH_GCONF)
USE_GNOME+=	gconf2
CONFIGURE_ARGS+=	--with-gconf
GCONF_SCHEMAS=	${PORTNAME}.schemas
.else
CONFIGURE_ARGS+=	--without-gconf --disable-schemas-install
.endif

.if defined(WITH_NOCACHE)
CONFIGURE_ARGS+=	--disable-caching
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|$$(libdir)/mozilla/plugins|${WEBPLUGINS_DIR}|' \
		${WRKSRC}/src/Makefile.in
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e \
		's|install-gecko_mediaplayerdocDATA install-schemaDATA|install-schemaDATA|' \
		${WRKSRC}/Makefile.in
.endif

.include "${PORTSDIR}/www/mozilla/bsd.gecko.mk"
.include "${PORTSDIR}/www/firefox/Makefile.webplugins"
.include <bsd.port.post.mk>
