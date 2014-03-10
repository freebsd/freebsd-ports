# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	gecko-mediaplayer
DISTVERSION=	1.0.9a
PORTREVISION=	2
CATEGORIES=	www multimedia gnome
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multimedia browser plugin for Gecko based browsers

LICENSE=	GPLv2

LIB_DEPENDS=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libnspr4.so:${PORTSDIR}/devel/nspr \
		libcurl.so:${PORTSDIR}/ftp/curl \
		libgmlib.so:${PORTSDIR}/multimedia/gmtk
RUN_DEPENDS=	gnome-mplayer:${PORTSDIR}/multimedia/gnome-mplayer

OPTIONS_DEFINE=	CACHE DOCS NLS
OPTIONS_DEFAULT=CACHE
CACHE_DESC=	Enable caching of remote media to local storage

GNU_CONFIGURE=	yes
USES=		compiler:c++11-lang pkgconfig
USE_GNOME=	glib20
USE_GECKO=	libxul
USE_WEBPLUGINS=	native

WEBPLUGINS_FILES=	${PORTNAME}.so
.for p in dvx rm qt wmp
WEBPLUGINS_FILES+=	${PORTNAME}-${p}.so
.endfor

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=--with-plugin_dir="${WEBPLUGINS_DIR}"

PORTDOCS=	README COPYING AUTHORS ChangeLog INSTALL NEWS javascript.txt

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCACHE}
CONFIGURE_ARGS+=	--enable-caching
.else
CONFIGURE_ARGS+=	--disable-caching
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB=	NLS=""
.else
USES+=		gettext:build
PLIST_SUB=	NLS="@comment "
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
.if empty(PORT_OPTIONS:MNLS)
	@${REINPLACE_CMD} -e 's/^ALL_LINGUAS=".*"/ALL_LINGUAS=""/' \
	    ${WRKSRC}/configure
.endif

.include "${PORTSDIR}/www/firefox/Makefile.webplugins"
.include <bsd.port.mk>
