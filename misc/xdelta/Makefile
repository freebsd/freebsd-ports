# New ports collection makefile for:    xdelta
# Version required:     0.18
# Date created:         Sun May  4 21:40:06 CDT 1997
# Whom:                 jmacd
#
# $Id: Makefile,v 1.6 1998/04/21 00:09:55 jmacd Exp $
#

DISTNAME=       xdelta-0.18
CATEGORIES=     misc
MASTER_SITES=   ftp://ftp.xcf.berkeley.edu/pub/jmacd/

MAINTAINER=	jmacd@FreeBSD.ORG

BUILD_DEPENDS=	${PREFIX}/lib/libgdbm.a:${PORTSDIR}/databases/gdbm

GNU_CONFIGURE=	yup
#
# this seems to be necessary for libtool :(
MAKE_ENV= CC=cc
MAN1=           xdelta.1

.include <bsd.port.mk>
