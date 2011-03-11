# New ports collection makefile for:	Lila-xfwm4
# Date created:		25 June 2004
# Whom:			Filippo Natali <filippo@widestore.net>
#
# $FreeBSD$
#

PORTNAME=	Lila-xfwm4
PORTVERSION=	0.3.1
PORTREVISION=	7
CATEGORIES=	x11-themes xfce
MASTER_SITES=	http://stief.tnux.net/Lila/
DIST_SUBDIR=	xfce4

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XFce 4 Lila window decoration theme for xfwm4

RUN_DEPENDS=	xfwm4:${PORTSDIR}/x11-wm/xfce4-wm

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

NO_BUILD=	yes

do-install:
	@${MKDIR} -p  ${PREFIX}/share/themes/Lila/xfwm4
	@${MKDIR} -p  ${PREFIX}/share/themes/Lila-light/xfwm4
	@${CP} -R ${WRKDIR}/Lila/ ${PREFIX}/share/themes/Lila/xfwm4
	@${CP} -R ${WRKDIR}/Lila-light/ ${PREFIX}/share/themes/Lila-light/xfwm4

.include <bsd.port.mk>
