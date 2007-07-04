# New ports collection makefile for:	nimbus
# Date created:		2007-04-27
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nimbus
PORTVERSION=	0.0.7
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

pre-configure:
	@(cd ${WRKSRC} && ${INTLTOOLIZE} -f)

post-patch:
	@${REINPLACE_CMD} -e 's|$$(datadir)|${PREFIX}/share/gnome|' \
		${WRKSRC}/metacity/Makefile.in

.include <bsd.port.mk>
