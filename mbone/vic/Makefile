# New ports collection makefile for:	vic
# Version required:	2.6
# Date created:		14 December 1994
# Whom:			wollman
#
# $Id: Makefile,v 1.4 1995/04/10 17:49:14 asami Exp $
#

DISTNAME=	vic-2.6
CATEGORIES+=	net
MASTER_SITES=	ftp://ftp.ee.lbl.gov/conferencing/vic/
DISTFILES=	vicsrc-2.6.tar.Z

MAINTAINER=	wollman@FreeBSD.ORG

LIB_DEPENDS=	BLT\\.1\\.:${PORTSDIR}/x11/blt

HAS_CONFIGURE=	yes
INSTALL_TARGET=	MANDIR=${PREFIX}/man/manl install

pre-install:
	mkdir -p ${PREFIX}/man/manl

.include <bsd.port.mk>

