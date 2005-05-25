# Ports collection Makefile for:	liferea
# Date created:		28 August 2003
# Whom:			Hye-Shik Chang <perky@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	liferea
PORTVERSION=	0.9.2
PORTREVISION=	1
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	liferea

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Simple RSS/RDF feed reader

USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack libgtkhtml
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_LIBTOOL_VER=15
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		liferea.1
GCONF_SCHEMAS=	liferea.schemas

OPTIONS=	DBUS "Enable dbus support" on

.include <bsd.port.pre.mk>

.ifdef WITH_MOZILLA
.if ${WITH_MOZILLA}=="mozilla" || ${WITH_MOZILLA}=="yes"
MOZILLA=	mozilla
MOZ_BUILD=	mozilla
.elif ${WITH_MOZILLA}=="mozilla-devel"
MOZILLA=	mozilla-devel
MOZ_BUILD=	mozilla
MOZ_SUFFIX=	-devel
.elif ${WITH_MOZILLA}=="firefox"
MOZILLA=	firefox
MOZ_BUILD=	firefox
.else
IGNORE=		: Available options for WITH_MOZILLA are: mozilla mozilla-devel firefox
.endif
.endif # WITH_MOZILLA

.ifdef MOZILLA
BUILD_DEPENDS=	${X11BASE}/lib/${MOZILLA}/components/libwidget_gtk2.so:${PORTSDIR}/www/${MOZILLA}
RUN_DEPENDS=	${X11BASE}/lib/${MOZILLA}/components/libwidget_gtk2.so:${PORTSDIR}/www/${MOZILLA} 
PLIST_SUB=	MOZ=""
.else
PLIST_SUB=	MOZ="@comment "
.endif

.ifdef WITHOUT_DBUS
CONFIGURE_ARGS+=--disable-dbus
.else
LIB_DEPENDS+=	dbus-1.1:${PORTSDIR}/devel/dbus
.endif

post-patch:
	${REINPLACE_CMD} -e 's,/usr/lib/mozilla,${X11BASE}/lib/${MOZ_BUILD},g' \
		${WRKSRC}/src/liferea
	${REINPLACE_CMD} -e 's,firefox-,$$gecko_provider-,g' \
		-e 's,\(gecko_provider=\).*$$,\1${MOZ_BUILD},' \
		-e 's,-gtkmozembed,-gtkmozembed${MOZ_SUFFIX},' \
		${WRKSRC}/configure
	${REINPLACE_CMD} -e 's,%FREEBSD_MOZILLA_HOME%,${X11BASE}/lib/${MOZILLA},' \
		${WRKSRC}/src/liferea

.include <bsd.port.post.mk>
