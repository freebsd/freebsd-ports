# New ports collection makefile for:	npadmin
# Version required:     0.7
# Date created:		13 Nov 1998
# Whom:			Dom Mitchell <dom@myrddin.demon.co.uk>
#
# $Id$
#

DISTNAME=	npadmin-0.7
CATEGORIES=	sysutils print
MASTER_SITES=	ftp://ftp.penguincomputing.com/pub/prtools/

MAINTAINER=	dom@myrddin.demon.co.uk

ALL_TARGET=	npadmin

MAN1=		npadmin.1

GNU_CONFIGURE=	yes

pre-build:
	${CP} ${FILESDIR}/getopt* ${WRKSRC}

.include <bsd.port.mk>
