# New ports collection makefile for: gpkgdep
# Date created:                      2002/11/28
# Whom:                              Heiner <h.eichmann@gmx.de>
#
# $FreeBSD$

PORTNAME=	gpkgdep
PORTVERSION=	0.2
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/

MAINTAINER=	h.eichmann@gmx.de
COMMENT=	Shows package dependencies in tree views

USE_BZIP2=	yes
USE_GNOME=	gtk20
USE_AUTOTOOLS=	automake:15 autoconf:262
AUTOMAKE_ARGS=	--add-missing
USE_GMAKE=	yes
PLIST_FILES=	bin/gpkgdep

.include <bsd.port.mk>
