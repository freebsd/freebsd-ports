# New ports collection makefile for:	nimbus
# Date created:		2007-04-27
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/x11-themes/nimbus/Makefile,v 1.5 2007/10/23 12:51:24 ahze Exp $

PORTNAME=	nimbus
PORTVERSION=	0.0.11
CATEGORIES=	x11-themes
MASTER_SITES=	http://dlc.sun.com/osol/jds/downloads/extras/

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	GNOME theme from Sun Microsystems

BUILD_DEPENDS=	gnome-themes>0:${PORTSDIR}/x11-themes/gnome-themes \
		icon-naming-utils>=0.8.2:${PORTSDIR}/x11-themes/icon-naming-utils
RUN_DEPENDS=	gnome-themes>0:${PORTSDIR}/x11-themes/gnome-themes

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
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
