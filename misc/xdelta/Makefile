# New ports collection makefile for:    xdelta
# Version required:     0.14
# Date created:         Sun May  4 21:40:06 CDT 1997
# Whom:                 erich
#
# $Id: Makefile,v 1.2 1998/01/28 22:44:32 asami Exp $
#

DISTNAME=       xdelta-0.14
CATEGORIES=     misc
MASTER_SITES=   ftp://scam.xcf.berkeley.edu/pub/jmacd/

BUILD_DEPENDS=	${PREFIX}/lib/libgdbm.a:${PORTSDIR}/databases/gdbm

GNU_CONFIGURE=	yup
#
# this seems to be necessary for libtool :(
MAKE_ENV= CC=cc

.include <bsd.port.mk>
