# New ports collection makefile for:	blt
# Version required:	1.7
# Date created:		14 December 1994
# Whom:			wollman
#
# $Id: Makefile,v 1.5 1995/06/24 11:42:19 asami Exp $
#

DISTNAME=	blt-1.7
CATEGORIES+=	x11
MASTER_SITES=	ftp://ftp.neosoft.com/pub/tcl/alcatel/extensions/
DISTFILES=	BLT-1.7.tar.gz

LIB_DEPENDS=	tk\\.3\\.:${PORTSDIR}/x11/tk

GNU_CONFIGURE=	yes
ALL_TARGET=	all sharedlib

post-install:
	ldconfig -m ${PREFIX}/lib

.include <bsd.port.mk>
