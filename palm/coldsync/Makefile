# New ports collection makefile for:	coldsync
# Date created:		21 January 2000
# Whom:			Andrew Arensburger <arensb@ooblick.com>
#
# $FreeBSD$
#

PORTNAME=	coldsync
PORTVERSION=	1.1.2
CATEGORIES=	palm comms
MASTER_SITES=	http://www.ooblick.com/software/coldsync/

MAINTAINER=	arensb@ooblick.com

GNU_CONFIGURE=	yes

MAN8=		coldsync.8
MANCOMPRESSED=	no

post-install:
	@install-info ${PREFIX}/info/conduits.info ${PREFIX}/info/dir
	@install-info ${PREFIX}/info/pdb.info ${PREFIX}/info/dir

.include <bsd.port.mk>
