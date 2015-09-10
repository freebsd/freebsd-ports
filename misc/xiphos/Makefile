# $FreeBSD$

PORTNAME=	xiphos
PORTVERSION=	3.1.6
PORTREVISION=	4
CATEGORIES=	misc gnome
MASTER_SITES=	SF/gnomesword/Xiphos/${PORTVERSION}

MAINTAINER=	tabthorpe@FreeBSD.org
COMMENT=	Bible interface utilizing the sword framework

LICENSE=	GPLv2

RUN_DEPENDS=	yelp:${PORTSDIR}/x11/yelp
BUILD_DEPENDS:=	${RUN_DEPENDS} \
		docbook2html:${PORTSDIR}/textproc/docbook-utils \
		gnome-doc-tool:${PORTSDIR}/textproc/gnome-doc-utils \
		nspr>=4.8:${PORTSDIR}/devel/nspr
LIB_DEPENDS=	libwebkitgtk-3.0.so:${PORTSDIR}/www/webkit-gtk3 \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib  \
		libsword.so:${PORTSDIR}/misc/sword

USES=		gettext pkgconfig waf
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
USE_GNOME=	gtkhtml4 intlhack gtk30 gconf2 libgsf

OPTIONS_DEFINE=	DOCS

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/share/icons/hicolor/icon-theme.cache

.include <bsd.port.options.mk>

.if ${OSVERSION} < 1000000
BROKEN=	Does not build on FreeBSD < 10.X
.endif

.include <bsd.port.mk>
