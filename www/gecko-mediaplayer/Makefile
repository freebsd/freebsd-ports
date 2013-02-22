# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	gecko-mediaplayer
PORTVERSION=	1.0.7
CATEGORIES=	www multimedia gnome
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multimedia browser plugin for Gecko based browsers

LICENSE=	GPLv2

LIB_DEPENDS=	dbus-glib-1:${PORTSDIR}/devel/dbus-glib \
		nspr4:${PORTSDIR}/devel/nspr \
		curl:${PORTSDIR}/ftp/curl \
		gmlib:${PORTSDIR}/multimedia/gmtk
RUN_DEPENDS=	gnome-mplayer:${PORTSDIR}/multimedia/gnome-mplayer

OPTIONS_DEFINE=	NOCACHE DOCS
NOCACHE_DESC=	Disable caching of remote media to local storage

GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
USE_PKGCONFIG=	build
USE_GNOME=	glib20
USE_GECKO=	libxul libxul19
USE_WEBPLUGINS=	native
WEBPLUGINS_FILES=	${PORTNAME}-dvx.so ${PORTNAME}-qt.so ${PORTNAME}-rm.so \
				${PORTNAME}-wmp.so ${PORTNAME}.so
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=--with-plugin_dir="${WEBPLUGINS_DIR}"

PORTDOCS=	README COPYING AUTHORS ChangeLog INSTALL NEWS javascript.txt

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNOCACHE}
CONFIGURE_ARGS+=	--disable-caching
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-ldl||' \
		${WRKSRC}/configure \
		${WRKSRC}/src/Makefile.in
.if empty(PORT_OPTIONS:MDOCS)
	@${REINPLACE_CMD} -e \
		's|install-gecko_mediaplayerdocDATA install-schemaDATA|install-schemaDATA|' \
		${WRKSRC}/Makefile.in
.endif

.include "${PORTSDIR}/www/firefox/Makefile.webplugins"
.include <bsd.port.mk>
