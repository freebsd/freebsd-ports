# $FreeBSD$

PORTNAME=	xiphos
PORTVERSION=	3.1.5
PORTREVISION=	4
CATEGORIES=	misc gnome
MASTER_SITES=	SF/gnomesword/Xiphos/${PORTVERSION}

MAINTAINER=	tabthorpe@FreeBSD.org
COMMENT=	A bible interface utilizing the sword framework

LICENSE=	GPLv2

RUN_DEPENDS=	${LOCALBASE}/lib/libsword-1.6.2.so:${PORTSDIR}/misc/sword \
		yelp:${PORTSDIR}/x11/yelp
BUILD_DEPENDS:=	${RUN_DEPENDS} \
		docbook2html:${PORTSDIR}/textproc/docbook-utils \
		gnome-doc-tool:${PORTSDIR}/textproc/gnome-doc-utils \
		nspr>=4.8:${PORTSDIR}/devel/nspr

USE_PYTHON_BUILD=	yes
USES=		gettext pkgconfig
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
USE_GNOME=	gnomehack gnomeprefix gtkhtml3 intlhack libgsf

OPTIONS_SINGLE=		BACKEND
OPTIONS_SINGLE_BACKEND=	GTKHTML WEBKIT
GTKHTML_DESC=		Use gtkhtml for rendering
WEBKIT_DESC=		Use webkit for rendering (preferred)

OPTIONS_DEFAULT=	WEBKIT

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MWEBKIT}
WAF_CONFIGURE_ARGS=	--backend=webkit
LIB_DEPENDS=		webkitgtk:${PORTSDIR}/www/webkit-gtk2
.endif

.if ${PORT_OPTIONS:MGTKHTML}
WAF_CONFIGURE_ARGS=	--backend=gtkhtml
.endif

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ./waf configure \
		--prefix=${PREFIX} --destdir=${PREFIX} \
		${WAF_CONFIGURE_ARGS} --gtk=2

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./waf build

do-install:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./waf install

.include <bsd.port.mk>
