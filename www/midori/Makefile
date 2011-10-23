# New ports collection makefile for:	midori
# Date created:		2007-10-21
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/www/midori/Makefile,v 1.21 2010/04/05 21:56:26 kwm Exp $
#

PORTNAME=	midori
PORTVERSION=	0.4.1
CATEGORIES=	www xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=	src/apps/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Lightweight web browser using WebKit browser engine

BUILD_DEPENDS=	rsvg-convert:${PORTSDIR}/graphics/librsvg2 \
		valac:${PORTSDIR}/lang/vala
LIB_DEPENDS=	webkitgtk-1.0.0:${PORTSDIR}/www/webkit-gtk2 \
		sqlite3.8:${PORTSDIR}/databases/sqlite3 \
		notify.4:${PORTSDIR}/devel/libnotify
RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=--enable-libnotify \
		--enable-addons \
		--enable-docs \
		--disable-gtk3 \
		--jobs=${MAKE_JOBS_NUMBER}

MAKE_JOBS_SAFE=	yes
HAS_CONFIGURE=	yes
USE_PYTHON_BUILD=	yes
USE_BZIP2=	yes
USE_GNOME=	glib20 gtk20 intltool libxml2 pkgconfig desktopfileutils
USE_XORG=	xscrnsaver
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
.endif

PLIST_SUB=	VERSION="${PORTVERSION:R}"

OPTIONS=	NLS "Enable Native Language support" on \
		APIDOCS "Build api documentation" off \
		UNIQUE "Enable single instance support" on

.include <bsd.port.pre.mk>

# WAF needs that
CONFIGURE_ENV+=	CC="${CC}"

.if !defined(WITHOUT_NLS)
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if defined(WITH_APIDOCS)
BUILD_DEPENDS+=	gtkdoc-scan:${PORTSDIR}/textproc/gtk-doc
CONFIGURE_ARGS+=--enable-apidocs
PLIST_SUB+=	APIDOCS=""
.else
CONFIGURE_ARGS+=--disable-apidocs
PLIST_SUB+=	APIDOCS="@comment "
.endif

.if defined(WITH_UNIQUE)
LIB_DEPENDS+=	unique-1.0.2:${PORTSDIR}/x11-toolkits/unique
CONFIGURE_ARGS+=--enable-unique
.else
CONFIGURE_ARGS+=--disable-unique
.endif

post-install:
	@-update-desktop-database
.if defined(WITH_APIDOCS)
	${MKDIR} ${DOCSDIR}/api/katze/html
	${MKDIR} ${DOCSDIR}/api/midori/html
	(cd ${WRKSRC}/_build_/docs/api/katze/html && ${COPYTREE_SHARE} \* ${DOCSDIR}/api/katze/html)
	(cd ${WRKSRC}/_build_/docs/api/midori/html && ${COPYTREE_SHARE} \* ${DOCSDIR}/api/midori/html)
.endif

.include <bsd.port.post.mk>
