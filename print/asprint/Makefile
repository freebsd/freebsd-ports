# New ports collection makefile for:	 asmail
# Version required:	1.0
# Date created:		16 August 1997
# Whom:			brett@peloton.physics.montana.edu
#
# $FreeBSD$
#

DISTNAME=	asprint
PKGNAME=	asprint-1.0
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.afterstep.org/apps/asprint/

MAINTAINER=	brett@peloton.runet.edu

USE_X_PREFIX=	yes
ALL_TARGET=	asprint
MAKEFILE=	makefile

do-install:
	${INSTALL_PROGRAM} $(WRKSRC)/asprint ${PREFIX}/bin

.include <bsd.port.mk>
