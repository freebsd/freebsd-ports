# New ports collection makefile for:	 asmail
# Version required:	1.0
# Date created:		16 August 1997
# Whom:			brett@peloton.physics.montana.edu
#
# $Id$
#

DISTNAME=	asprint
PKGNAME=	asprint-1.0
CATEGORIES=	print
MASTER_SITES=	ftp://afterstep.foo.net/pub/AfterStep/apps/asprint/

MAINTAINER=	brett@peloton.physics.montana.edu

USE_X11=	yes
ALL_TARGET=	asprint
MAKEFILE=	makefile

do-install:
	${INSTALL_PROGRAM} $(WRKSRC)/asprint ${PREFIX}/bin

.include <bsd.port.mk>
