# Ports collection Makefile for:	liferea
# Date created:		28 August 2003
# Whom:			Hye-Shik Chang <perky@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	liferea
PORTVERSION=	1.4.17
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	liferea

MAINTAINER=	pav@FreeBSD.org
COMMENT=	Simple RSS/RDF feed reader

LIB_DEPENDS=	sqlite3.8:${PORTSDIR}/databases/sqlite3

USE_GECKO=	firefox mozilla
USE_GNOME=	gnomeprefix gnomehack libgtkhtml libglade2
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		liferea.1
MANLANG=	"" pl
GCONF_SCHEMAS=	liferea.schemas
INSTALLS_ICONS=	yes

OPTIONS=	LIBNOTIFY "Enable libnotify support" on \
		DBUS "Enable dbus support" on \
		GNUTLS "Enable SSL/HTTPS support" on \
		MOZILLA "Use Firefox for rendering" off \
		XULRUNNER "Use Xulrunner for rendering" off

.include <bsd.port.pre.mk>

.ifdef WITHOUT_LIBNOTIFY
CONFIGURE_ARGS+=--disable-libnotify
PLIST_SUB+=	NOTIFY="@comment "
.else
LIB_DEPENDS+=	notify.1:${PORTSDIR}/devel/libnotify
PLIST_SUB+=	NOTIFY=""
.endif

.ifdef WITHOUT_GNUTLS
CONFIGURE_ARGS+=--disable-gnutls
.else
LIB_DEPENDS+=	gnutls.26:${PORTSDIR}/security/gnutls
.endif

.ifdef WITH_MOZILLA
.include "${PORTSDIR}/www/mozilla/bsd.gecko.mk"
CONFIGURE_ARGS+=--enable-gecko=${GECKO}
PLIST_SUB+=	MOZ=""
.else
CONFIGURE_ARGS+=--disable-gecko
PLIST_SUB+=	MOZ="@comment "
.endif

.ifdef WITH_XULRUNNER
BUILD_DEPENDS+=	xulrunner:${PORTSDIR}/www/xulrunner
RUN_DEPENDS+=	xulrunner:${PORTSDIR}/www/xulrunner
PLIST_SUB+=	XUL=""
.else
CONFIGURE_ARGS+=--disable-xulrunner
PLIST_SUB+=	XUL="@comment "
.endif

.ifdef WITHOUT_DBUS
CONFIGURE_ARGS+=--disable-dbus
.else
LIB_DEPENDS+=	dbus-1.3:${PORTSDIR}/devel/dbus
.endif

post-patch:
.ifdef WITH_MOZILLA
	@${REINPLACE_CMD} -e 's,firefox-,$$gecko_provider-,g' \
		-e 's,\(gecko_provider=\).*$$,\1${GECKO},' \
		-e '/INCLUDE/s,{print $$1},{print $$2},g' \
		${WRKSRC}/configure
.endif

.include <bsd.port.post.mk>
