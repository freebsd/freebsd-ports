# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	midori
PORTVERSION=	0.5.5
CATEGORIES=	www xfce
MASTER_SITES=	http://www.midori-browser.org/downloads/
DISTNAME=	${PORTNAME}_${PORTVERSION}_all_
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Lightweight web browser using WebKit browser engine

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	rsvg-convert:${PORTSDIR}/graphics/librsvg2 \
		valac:${PORTSDIR}/lang/vala
LIB_DEPENDS=	webkitgtk-1:${PORTSDIR}/www/webkit-gtk2 \
		sqlite3:${PORTSDIR}/databases/sqlite3 \
		notify:${PORTSDIR}/devel/libnotify \
		soup-gnome-2:${PORTSDIR}/devel/libsoup-gnome \
		execinfo:${PORTSDIR}/devel/libexecinfo
RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=--enable-addons \
		--enable-docs \
		--disable-gtk3 \
		--jobs=${MAKE_JOBS_NUMBER}

WRKSRC=	${WRKDIR}/${DISTNAME:C/([a-z]*)_([0-9\.]*)(_all_)/\1-\2/}
HAS_CONFIGURE=	yes
USE_PYTHON=	-2.7
USE_PYTHON_BUILD=	yes
USE_BZIP2=	yes
USE_GNOME=	glib20 gtk20 intltool libxml2
USE_XORG=	xscrnsaver
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
USES=		desktop-file-utils pkgconfig

PLIST_SUB=	VERSION="${PORTVERSION:R}"

OPTIONS_DEFINE=	DOCS NLS UNIQUE ZEITGEIST
OPTIONS_DEFAULT=	NLS UNIQUE

UNIQUE_DESC=	Single instance support
ZEITGEIST_DESC=	User logs activities

.include <bsd.port.options.mk>

# WAF needs that
CONFIGURE_ENV+=	CC="${CC}"

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	gtkdoc-scan:${PORTSDIR}/textproc/gtk-doc
CONFIGURE_ARGS+=--enable-apidocs
PLIST_SUB+=	APIDOCS=""
.else
CONFIGURE_ARGS+=--disable-apidocs
PLIST_SUB+=	APIDOCS="@comment "
.endif

.if ${PORT_OPTIONS:MUNIQUE}
LIB_DEPENDS+=	unique-1:${PORTSDIR}/x11-toolkits/unique
CONFIGURE_ARGS+=--enable-unique
.else
CONFIGURE_ARGS+=--disable-unique
.endif

.if ${PORT_OPTIONS:MZEITGEIST}
LIB_DEPENDS+=	zeitgeist-1:${PORTSDIR}/sysutils/libzeitgeist
CONFIGURE_ARGS+=--enable-zeitgeist
.else
CONFIGURE_ARGS+=--disable-zeitgeist
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
.for dir in katze midori
	@${MKDIR} ${DOCSDIR}/api/${dir}/html
	@cd ${WRKSRC}/_build/docs/api/${dir}/html && \
		${COPYTREE_SHARE} . ${DOCSDIR}/api/${dir}/html
.endfor
.endif

.include <bsd.port.mk>
