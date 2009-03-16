# Ports collection Makefile for:	liferea
# Date created:		28 August 2003
# Whom:			Hye-Shik Chang <perky@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	liferea
PORTVERSION=	1.4.27
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	liferea

MAINTAINER=	pav@FreeBSD.org
COMMENT=	Simple RSS/RDF feed reader

LIB_DEPENDS=	sqlite3.8:${PORTSDIR}/databases/sqlite3

USE_GNOME=	gnomeprefix gnomehack libglade2
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
		GTKHTML "Use GtkHtml for rendering" on \
		WEBKIT "Use Webkit for rendering" off
#		MOZILLA "Use Firefox for rendering" off \
#		XULRUNNER "Use Xulrunner for rendering" off

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

.ifdef WITH_GTKHTML
USE_GNOME+=	libgtkhtml
CONFIGURE_ARGS+=--enable-gtkhtml2
PLIST_SUB+=	GTKHTML=""
.else
CONFIGURE_ARGS+=--disable-gtkhtml2
PLIST_SUB+=	GTKHTML="@comment "
.endif

.ifdef WITH_WEBKIT
LIB_DEPENDS+=	webkit-1.0.1:${PORTSDIR}/www/webkit-gtk2
CONFIGURE_ARGS+=--enable-webkit
PLIST_SUB+=	WEBKIT=""
.else
CONFIGURE_ARGS+=--disable-webkit
PLIST_SUB+=	WEBKIT="@comment "
.endif

.ifdef WITH_MOZILLA
USE_GNOME+=	gconf2 libxslt
USE_GECKO=	firefox mozilla
CONFIGURE_ARGS+=--with-gecko=${GECKO}
PLIST_SUB+=	MOZ=""
BROKEN=		does not compile
.else
PLIST_SUB+=	MOZ="@comment "
.endif

.ifdef WITH_XULRUNNER
CONFIGURE_ARGS+=--with-gecko=xulrunner
BUILD_DEPENDS+=	xulrunner:${PORTSDIR}/www/xulrunner
RUN_DEPENDS+=	xulrunner:${PORTSDIR}/www/xulrunner
PLIST_SUB+=	XUL=""
BROKEN=		does not configure
.else
PLIST_SUB+=	XUL="@comment "
.endif

.if !defined(WITH_MOZILLA) && !defined(WITH_XULRUNNER)
CONFIGURE_ARGS+=--disable-gecko
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
