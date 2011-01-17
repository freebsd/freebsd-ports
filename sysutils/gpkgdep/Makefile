# New ports collection makefile for: gpkgdep
# Date created:                      2002/11/28
# Whom:                              Heiner <h.eichmann@gmx.de>
#
# $FreeBSD$

PORTNAME=	gpkgdep
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/

MAINTAINER=	michael@fun-box.ru
COMMENT=	Shows package dependencies in tree views

LICENSE=	GPLv2

USE_BZIP2=	yes
USE_GNOME=	gtk20
USE_AUTOTOOLS=	automake14 autoconf
AUTOMAKE_ARGS=	--add-missing
USE_GMAKE=	yes
PLIST_FILES=	bin/gpkgdep

.include <bsd.port.mk>
