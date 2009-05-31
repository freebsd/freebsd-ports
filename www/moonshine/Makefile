# New ports collection makefile for:	moonshine
# Date created:				May 14 2009
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	moonshine
PORTVERSION=	0.2
CATEGORIES=	www multimedia
MASTER_SITES=	http://abock.org/${PORTNAME}/releases/

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Windows Media playback through Moonlight and Firefox

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GECKO=	libxul
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-browser-plugin-dir=${PREFIX}/lib/browser_plugins/${PORTNAME}/

USE_WEBPLUGINS=		gecko19
WEBPLUGINS_DIR=		${PREFIX}/lib/browser_plugins/${PORTNAME}/
WEBPLUGINS_FILES=	libmoonshine-plugin.so

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/firefox/Makefile.webplugins"

.if ${ARCH} == "amd64"
BROKEN=		does not configure
.endif

.if defined(WITH_XPI_PLUGIN_ONLY)
CONFIGURE_ARGS+=--enable-xpi-build
PLIST=		${NONEXISTENT}
PLIST_FILES=	${WEBPLUGINS_DIR}/${PKGNAME}-freebsd-${OSREL}.xpi
.endif

post-patch:
	${REINPLACE_CMD} -e 's|^SHELL=.*|SHELL=${LOCALBASE}/bin/bash|' \
		${WRKSRC}/configure 
	${REINPLACE_CMD} -e 's|sed -r|sed -E|' \
		${WRKSRC}/plugin/Makefile.in \
		${WRKSRC}/plugin/generate-resource

.if defined(WITH_XPI_PLUGIN_ONLY)
do-install:
	${INSTALL_DATA} ${WRKSRC}/plugin/xpi/moonshine.xpi \
		${WEBPLUGINS_DIR}/${PKGNAME}-freebsd-${OSREL}.xpi
.endif

.include <bsd.port.post.mk>
