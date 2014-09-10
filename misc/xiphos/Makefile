# $FreeBSD$

PORTNAME=	xiphos
PORTVERSION=	3.1.6
PORTREVISION=	1
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

USE_PYTHON_BUILD=	yes
USES=		gettext pkgconfig
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
USE_GNOME=	gnomehack gnomeprefix gtkhtml3 intlhack libgsf

OPTIONS_DEFINE=	DOCS

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ./waf configure \
		--prefix=${STAGEDIR}${PREFIX} --destdir=${STAGEDIR}${PREFIX} \
		${WAF_CONFIGURE_ARGS}

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./waf build

do-install:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./waf install

.include <bsd.port.mk>
