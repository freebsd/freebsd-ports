# $FreeBSD$

PORTNAME=	xiphos
PORTVERSION=	3.1.6
PORTREVISION=	2
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
LIB_DEPENDS=	libwebkitgtk-1.0.so:${PORTSDIR}/www/webkit-gtk2 \
		libsword.so:${PORTSDIR}/misc/sword

USES=		gettext pkgconfig python:build
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
USE_GNOME=	gnomeprefix gtkhtml3 intlhack libgsf

OPTIONS_DEFINE=	DOCS

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ./waf configure \
		--prefix=${PREFIX} --destdir=${STAGEDIR} \
		${WAF_CONFIGURE_ARGS}

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./waf build --prefix=${PREFIX} --destdir=${STAGEDIR}

do-install:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./waf install --prefix=${PREFIX} --destdir=${STAGEDIR}
	@${RM} ${STAGEDIR}${PREFIX}/share/icons/hicolor/icon-theme.cache

.include <bsd.port.mk>
