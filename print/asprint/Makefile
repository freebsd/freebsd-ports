# New ports collection makefile for:	 asmail
# Date created:		16 August 1997
# Whom:			brett@peloton.physics.montana.edu
#
# $FreeBSD$
#

PORTNAME=	asprint
PORTVERSION=	1.0
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_AFTERSTEP}
MASTER_SITE_SUBDIR=	apps/asprint
DISTNAME=	asprint

MAINTAINER=	brett@peloton.runet.edu
COMMENT=	A simple browser to allow a user to print

PLIST_FILES=	bin/asprint
USE_X_PREFIX=	yes
ALL_TARGET=	asprint
MAKEFILE=	makefile

do-install:
	${INSTALL_PROGRAM} $(WRKSRC)/asprint ${PREFIX}/bin

.include <bsd.port.mk>
