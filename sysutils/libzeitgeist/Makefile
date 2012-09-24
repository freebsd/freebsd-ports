# $FreeBSD$

PORTNAME=	libzeitgeist
PORTVERSION=	0.3.14
CATEGORIES=	sysutils
MASTER_SITES=	https://launchpad.net/${PORTNAME}/${PORTVERSION:R}/${PORTVERSION}/+download/ \
	https://launchpadlibrarian.net/92774729/

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Zeitgeist client library

RUN_DEPENDS=	zeitgeist-daemon:${PORTSDIR}/sysutils/zeitgeist

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack glib20 intltool intlhack
USE_GETTEXT=	yes
USE_PKGCONFIG=	build
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS=	gtkdoc-check:${PORTSDIR}/textproc/gtk-doc
CONFIGURE_ARGS+=--enable-gtk-doc-html \
	--with-html-dir=${PREFIX}/share/gtk-doc/html
PLIST_SUB+=	DOCS=""
.else
CONFIGURE_ARGS+=--disable-gtk-doc-html \
	--without-html-dir
PLIST_SUB+=	DOCS="@comment "
.endif

.include <bsd.port.mk>
