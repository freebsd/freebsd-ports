# New ports collection makefile for:	blt
# Version required:	1.7
# Date created:		14 December 1994
# Whom:			wollman
#
# $Id: Makefile,v 1.4 1995/04/12 20:30:53 asami Exp $
#

DISTNAME=	blt-1.7
CATEGORIES+=	x11
MASTER_SITES=	ftp://ftp.aud.alcatel.com/tcl/extensions/
DISTFILES=	BLT-1.7.tar.gz

LIB_DEPENDS=	tk\\.3\\.:${PORTSDIR}/x11/tk

GNU_CONFIGURE=	yes
ALL_TARGET=	all sharedlib

post-install:
	ldconfig -m ${PREFIX}/lib

.include <bsd.port.mk>
