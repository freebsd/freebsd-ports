# $FreeBSD$

PORTNAME=	libzeitgeist
PORTVERSION=	0.3.18
CATEGORIES=	sysutils
MASTER_SITES=	https://launchpadlibrarian.net/100152436/ \
	https://launchpad.net/${PORTNAME}/${PORTVERSION:R}/${PORTVERSION}/+download/ \
	LOCAL/olivierd

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Zeitgeist client library

USES=	pathfix pkgconfig gettext
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	glib20 intltool intlhack
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

NO_STAGE=	yes
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
