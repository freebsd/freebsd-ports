# New ports collection makefile for:	PARI
# Version required:	2.0.16b
# Date created:		19 January 1999
# Whom:	Yoshiaki UCHIKAWA <yoshiaki@kt.rim.or.jp>
#
# $Id: Makefile,v 1.7 1999/07/04 21:29:55 steve Exp $
#

DISTNAME=	pari-2.0.16.beta
PKGNAME=	pari-2.0.16b
CATEGORIES=	math
MASTER_SITES=   ftp://megrez.math.u-bordeaux.fr/pub/pari/unix/ \
				ftp://hasse.mathematik.tu-muenchen.de/pub/pari/

MAINTAINER=     yoshiaki@kt.rim.or.jp

ONLY_FOR_ARCHS=	i386

HAS_CONFIGURE = Yes
CONFIGURE_SCRIPT = Configure
CONFIGURE_ARGS = --prefix=${PREFIX}
CFLAGS=

USE_GMAKE = Yes
MAKE_ARGS= 	gp

MAN1=		gp.1

post-install:
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
