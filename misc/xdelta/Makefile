# New ports collection makefile for:    xdelta
# Version required:     0.14
# Date created:         Sun May  4 21:40:06 CDT 1997
# Whom:                 erich
#
# $Id: Makefile,v 1.3 1998/02/05 15:18:25 erich Exp $
#

DISTNAME=       xdelta-0.14
CATEGORIES=     misc
MASTER_SITES=   ftp://scam.xcf.berkeley.edu/pub/jmacd/

MAINTAINER=	ports@FreeBSD.ORG

BUILD_DEPENDS=	${PREFIX}/lib/libgdbm.a:${PORTSDIR}/databases/gdbm

GNU_CONFIGURE=	yup
#
# this seems to be necessary for libtool :(
MAKE_ENV= CC=cc

.include <bsd.port.mk>
