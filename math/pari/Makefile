# New ports collection makefile for:	PARI
# Version required:	2.0.13a
# Date created:		19 January 1999
# Whom:	Yoshiaki UCHIKAWA <yoshiaki@kt.rim.or.jp>
#
# $Id:$
#

DISTNAME=	pari-2.0.13.alpha
PKGNAME=	pari-2.0.13a
CATEGORIES=	math
MASTER_SITES=   ftp://megrez.math.u-bordeaux.fr/pub/pari/unix/ \
				ftp://hasse.mathematik.tu-muenchen.de/pub/pari/

MAINTAINER=     yoshiaki@kt.rim.or.jp

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
