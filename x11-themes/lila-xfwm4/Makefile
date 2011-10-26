# New ports collection makefile for:	Lila-xfwm4
# Date created:		25 June 2004
# Whom:			Filippo Natali <filippo@widestore.net>
#
# $FreeBSD$
#

PORTNAME=	Lila-xfwm4
PORTVERSION=	0.3.2
CATEGORIES=	x11-themes xfce
MASTER_SITES=	SF/lila-theme/lila-xfwm/${PORTVERSION}
DISTNAME=	lila-xfwm-${PORTVERSION}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Xfce 4 Lila window decoration theme for Xfwm4

RUN_DEPENDS=	xfwm4:${PORTSDIR}/x11-wm/xfce4-wm

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

USE_BZIP2=	yes

do-install:
	@${MKDIR} ${PREFIX}/share/themes/Lila/xfwm4
	@cd ${WRKSRC}/lila-xfwm/Lila \
		&& ${COPYTREE_SHARE} . ${PREFIX}/share/themes/Lila/xfwm4
	@${MKDIR} ${PREFIX}/share/themes/Lila-light/xfwm4
	@cd ${WRKSRC}/lila-xfwm/Lila-light \
		&& ${COPYTREE_SHARE} . ${PREFIX}/share/themes/Lila-light/xfwm4

.include <bsd.port.mk>
