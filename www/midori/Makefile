# New ports collection makefile for:	midori
# Date created:		2007-10-21
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/www/midori/Makefile,v 1.21 2010/04/05 21:56:26 kwm Exp $
#

PORTNAME=	midori
PORTVERSION=	0.2.6
PORTREVISION=	1
CATEGORIES=	www xfce
MASTER_SITES=	http://archive.xfce.org/src/apps/${PORTNAME}/${PORTVERSION:R}/
DIST_SUBDIR=	xfce4

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Lightweight web browser using WebKit browser engine

LIB_DEPENDS=	webkit-1.0:${PORTSDIR}/www/webkit-gtk2 \
		notify.1:${PORTSDIR}/devel/libnotify \
		vala.0:${PORTSDIR}/lang/vala
BUILD_DEPENDS=	rsvg-convert:${PORTSDIR}/graphics/librsvg2

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS+=--disable-unique \
		--disable-libidn \
		--enable-sqlite \
		--enable-libnotify \
		--enable-addons \
		--jobs=${MAKE_JOBS_NUMBER}

MAKE_JOBS_SAFE=	yes
HAS_CONFIGURE=	yes
USE_PYTHON_BUILD=	yes
USE_BZIP2=	yes
USE_GNOME=	glib20 gtk20 intltool libxml2 pkgconfig
USE_XORG=	xscrnsaver
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes

OPTIONS=	NLS "Enable Native Language support" on \
		USERDOCS "Build user documentation" off \
		APIDOCS "Build api documentation" off

.include <bsd.port.pre.mk>

# WAF needs that
CONFIGURE_ENV+=	CC="${CC}"

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if defined(WITH_USERDOCS)
BUILD_DEPENDS+=rst2html:${PORTSDIR}/textproc/py-docutils
CONFIGURE_ARGS+=--enable-userdocs
PLIST_SUB+=	USERDOCS=""
.else
CONFIGURE_ARGS+=--disable-userdocs
PLIST_SUB+=	USERDOCS="@comment "
.endif

.if defined(WITH_APIDOCS)
BUILD_DEPENDS+=	gtkdoc-scan:${PORTSDIR}/textproc/gtk-doc
CONFIGURE_ARGS+=--enable-apidocs  
PLIST_SUB+=	APIDOCS=""
.else
CONFIGURE_ARGS+=--disable-apidocs
PLIST_SUB+=	APIDOCS="@comment "
.endif

post-install:
.if defined(WITH_APIDOCS)
	${MKDIR} ${DOCSDIR}/api/katze/html
	${MKDIR} ${DOCSDIR}/api/midori/html
	(cd ${WRKSRC}/_build_/docs/api/katze/html && ${COPYTREE_SHARE} \* ${DOCSDIR}/api/katze/html)
	(cd ${WRKSRC}/_build_/docs/api/midori/html && ${COPYTREE_SHARE} \* ${DOCSDIR}/api/midori/html)
.endif

.include <bsd.port.post.mk>
