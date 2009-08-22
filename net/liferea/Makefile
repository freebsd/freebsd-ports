# Ports collection Makefile for:	liferea
# Date created:		28 August 2003
# Whom:			Hye-Shik Chang <perky@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	liferea
PORTVERSION=	1.4.28
PORTREVISION=	2
CATEGORIES=	net gnome
MASTER_SITES=	SF/${PORTNAME}/Liferea%20Stable/${PORTVERSION}

MAINTAINER=	pav@FreeBSD.org
COMMENT=	Simple RSS/RDF feed reader

LIB_DEPENDS=	sqlite3.8:${PORTSDIR}/databases/sqlite3

USE_GNOME=	gnomeprefix gnomehack libglade2
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
MAKE_JOBS_SAFE=	yes

MAN1=		liferea.1
MANLANG=	"" pl
GCONF_SCHEMAS=	liferea.schemas
INSTALLS_ICONS=	yes

OPTIONS=	LIBNOTIFY "Enable libnotify support" on \
		DBUS "Enable dbus support" on \
		GNUTLS "Enable SSL/HTTPS support" on \
		GTKHTML "Use GtkHtml for rendering" on \
		WEBKIT "Use Webkit for rendering" off
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
LIB_DEPENDS+=	gnutls.40:${PORTSDIR}/security/gnutls
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

.ifdef WITH_XULRUNNER
CONFIGURE_ARGS+=--with-gecko=libxul
BUILD_DEPENDS+=	${LOCALBASE}/lib/libxul/libxul.so:${PORTSDIR}/www/libxul
RUN_DEPENDS+=	${LOCALBASE}/lib/libxul/libxul.so:${PORTSDIR}/www/libxul
PLIST_SUB+=	XUL=""
.else
CONFIGURE_ARGS+=--disable-gecko
PLIST_SUB+=	XUL="@comment "
.endif

.ifdef WITHOUT_DBUS
CONFIGURE_ARGS+=--disable-dbus
.else
LIB_DEPENDS+=	dbus-1.3:${PORTSDIR}/devel/dbus
.endif

.include <bsd.port.post.mk>
