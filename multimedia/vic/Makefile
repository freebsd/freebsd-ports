# New ports collection makefile for:	vic
# Version required:	2.6
# Date created:		14 December 1994
# Whom:			wollman
#
# $Id: Makefile,v 1.3 1995/04/01 12:48:46 jkh Exp $
#

DISTNAME=	vic-2.6
CATEGORIES+=	networking
MASTER_SITES=	ftp://ftp.ee.lbl.gov/conferencing/vic/
DISTFILES=	vicsrc-2.6.tar.Z

MAINTAINER=	wollman@FreeBSD.ORG

LIB_DEPENDS=	BLT\\.1\\.:${PORTSDIR}/x11/blt

HAS_CONFIGURE=	yes
INSTALL_TARGET=	MANDIR=${PREFIX}/man/manl install

pre-install:
	mkdir -p ${PREFIX}/man/manl

.include <bsd.port.mk>

