# New ports collection makefile for: gpkgdep
# Date created:                      2002/11/28
# Whom:                              Heiner <h.eichmann@gmx.de>
#
# $FreeBSD$

PORTNAME=	gpkgdep
PORTVERSION=	0.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gpkgdep

MAINTAINER=	h.eichmann@gmx.de
COMMENT=	Shows package dependencies in tree views

LIB_DEPENDS=	gtk-x11-2.0.0:${PORTSDIR}/x11-toolkits/gtk20

USE_BZIP2=	yes
USE_AUTOMAKE_VER=	15
AUTOMAKE_ARGS=	--add-missing
USE_GMAKE=	yes

.include <bsd.port.mk>
