# New ports collection makefile for:	 asmail
# Version required:	1.0
# Date created:		16 August 1997
# Whom:			brett@peloton.physics.montana.edu
#
# $Id: Makefile,v 1.3 1998/10/12 12:33:23 jseger Exp $
#

DISTNAME=	asprint
PKGNAME=	asprint-1.0
CATEGORIES=	print
MASTER_SITES=	ftp://afterstep.foo.net/pub/AfterStep/apps/asprint/

MAINTAINER=	brett@peloton.physics.montana.edu

USE_X_PREFIX=	yes
ALL_TARGET=	asprint
MAKEFILE=	makefile

do-install:
	${INSTALL_PROGRAM} $(WRKSRC)/asprint ${PREFIX}/bin

.include <bsd.port.mk>
