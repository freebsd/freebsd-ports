# Ports collection Makefile for:	liferea
# Date created:		28 August 2003
# Whom:			Hye-Shik Chang <perky@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	liferea
PORTVERSION=	1.0.11
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	liferea

MAINTAINER=	pav@FreeBSD.org
COMMENT=	Simple RSS/RDF feed reader

USE_X_PREFIX=	yes
USE_GECKO=	mozilla firefox
USE_GNOME=	gnomeprefix gnomehack libgtkhtml
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		liferea.1
GCONF_SCHEMAS=	liferea.schemas

OPTIONS=	DBUS "Enable dbus support" on \
		MOZILLA "Use Mozilla for rendering" off

.include <bsd.port.pre.mk>

.ifdef WITH_MOZILLA
.include "${PORTSDIR}/www/mozilla/bsd.gecko.mk"
CONFIGURE_ARGS+=--enable-gecko=${GECKO}
PLIST_SUB=	MOZ=""
.else
CONFIGURE_ARGS+=--disable-gecko
PLIST_SUB=	MOZ="@comment "
.endif

.ifdef WITHOUT_DBUS
CONFIGURE_ARGS+=--disable-dbus
.else
LIB_DEPENDS+=	dbus-1.2:${PORTSDIR}/devel/dbus
.endif

post-patch:
.ifdef WITH_MOZILLA
	${REINPLACE_CMD} -e 's,/usr/lib/mozilla,${X11BASE}/lib/${GECKO},g ; \
		s,%FREEBSD_MOZILLA_HOME%,${X11BASE}/lib/${GECKO},' \
		${WRKSRC}/src/liferea.in
	${REINPLACE_CMD} -e 's,firefox-,$$gecko_provider-,g' \
		-e 's,\(gecko_provider=\).*$$,\1${GECKO},' \
		-e 's,{print $$1},{print $$2},g' \
		${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|gtk_moz_embed_set_comp_path(NULL)|gtk_moz_embed_set_comp_path("${X11BASE}/lib/${GECKO}")|' \
		${WRKSRC}/src/mozilla/mozembed.c
.endif

.include <bsd.port.post.mk>
