# New ports collection makefile for:	moonshine
# Date created:				May 14 2009
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	moonshine
PORTVERSION=	0.7
PORTREVISION=	2
CATEGORIES=	www multimedia
MASTER_SITES=	http://romain.blogreen.org/distfiles/
DISTNAME=	abock-${PORTNAME}-${GITCOMMIT}

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Windows Media playback through Moonlight and Firefox

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash
GITCOMMIT=	35085a4

USE_GMAKE=	yes
USE_GECKO=	libxul
USE_AUTOTOOLS=	libtool:22 libtoolize aclocal:111 autoconf:267 autoheader:267 automake:111
LIBTOOLIZE_ARGS=	--force --copy --automake
AUTOMAKE_ARGS=	--gnu --add-missing --force --copy -Wno-portability
ACLOCAL_ARGS=	
CONFIGURE_ARGS=	--with-browser-plugin-dir=${PREFIX}/lib/browser_plugins/${PORTNAME}/

USE_WEBPLUGINS=		gecko19
WEBPLUGINS_DIR=		${PREFIX}/lib/browser_plugins/${PORTNAME}/
WEBPLUGINS_FILES=	libmoonshine-plugin.so

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/firefox/Makefile.webplugins"

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	"not yet ported to anything other than i386 and amd64"

.if defined(WITH_XPI_PLUGIN_ONLY)
CONFIGURE_ARGS+=--enable-xpi-build
PLIST=		${NONEXISTENT}
PLIST_FILES=	${WEBPLUGINS_DIR}/${PKGNAME}-freebsd-${OSREL}.xpi
.endif

post-patch:
	${REINPLACE_CMD} -e 's|#!/bin/bash|#!${LOCALBASE}/bin/bash|' \
		${WRKSRC}/plugin/xpi/dist-build/build-all-arch \
		${WRKSRC}/xulrunner/icon-theme-hicolor/icon-theme-installer
	${REINPLACE_CMD} -e 's|sed -r|sed -E|' \
		${WRKSRC}/plugin/Makefile.am \
		${WRKSRC}/plugin/generate-resource

.if defined(WITH_XPI_PLUGIN_ONLY)
do-install:
	${INSTALL_DATA} ${WRKSRC}/plugin/xpi/moonshine.xpi \
		${WEBPLUGINS_DIR}/${PKGNAME}-freebsd-${OSREL}.xpi
.endif

.include <bsd.port.post.mk>
