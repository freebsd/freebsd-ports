# New ports collection makefile for:	PARI
# Version required:	2.0.16b
# Date created:		19 January 1999
# Whom:	Yoshiaki UCHIKAWA <yoshiaki@kt.rim.or.jp>
#
# $FreeBSD$
#

DISTNAME=	pari-2.0.16.beta
PKGNAME=	pari-2.0.16b
CATEGORIES=	math
MASTER_SITES=	ftp://hasse.mathematik.tu-muenchen.de/pub/pari/

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
