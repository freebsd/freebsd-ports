# New ports collection makefile for:	nimbus
# Date created:		2007-04-27
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/x11-themes/nimbus/Makefile,v 1.7 2008/03/18 19:01:43 ahze Exp $

PORTNAME=	nimbus
PORTVERSION=	0.0.12
CATEGORIES=	x11-themes
MASTER_SITES=	http://dlc.sun.com/osol/jds/downloads/extras/

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	GNOME theme from Sun Microsystems

BUILD_DEPENDS=	gnome-themes>0:${PORTSDIR}/x11-themes/gnome-themes \
		icon-naming-utils>=0.8.2:${PORTSDIR}/x11-themes/icon-naming-utils
RUN_DEPENDS=	gnome-themes>0:${PORTSDIR}/x11-themes/gnome-themes

USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool:15
USE_GMAKE=	yes
INSTALLS_ICONS=	yes
USE_GNOME=	intltool
INTLTOOLIZE?=	${LOCALBASE}/bin/intltoolize
CONFIGURE_ARGS=	--localedir=${PREFIX}/share/locale

post-patch:
	@${REINPLACE_CMD} -e 's|$${libdir}/locale|$${datadir}/locale|' \
		${WRKSRC}/aclocal.m4
	@${REINPLACE_CMD} -e 's|DATADIRNAME=lib|DATADIRNAME=share|' \
		${WRKSRC}/configure

pre-configure:
	@(cd ${WRKSRC} && ${INTLTOOLIZE} -f)

.include <bsd.port.mk>
