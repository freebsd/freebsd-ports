# New ports collection makefile for:	nte
# Version required:			1.5a23
# Date created:				5 September 1996
# Whom:	      Bill Fenner <fenner@FreeBSD.ORG>
#
#   $Id: Makefile,v 1.3 1996/11/26 11:21:25 asami Exp $
#

DISTNAME=	nt.1.5a23
PKGNAME=	nte-1.5a23
CATEGORIES=	mbone
MASTER_SITES=	ftp://cs.ucl.ac.uk/mice/nte/

MAINTAINER=	fenner@FreeBSD.org

TK_DIR=         ${PORTSDIR}/x11/tk41
TK_SRC=		${TK_DIR}/work/tk4.1

DEPENDS=	${TK_DIR}
LIB_DEPENDS=	tk41\\.1:${TK_DIR}

RESTRICTED=	"Contains DES encryption"
NO_WRKSUBDIR=	yes
USE_GMAKE=	yes
USE_X11=	yes
# Pass this on to our child
MAKE_ENV=	TK_SRC=${TK_SRC}

#DISGUSTING HACK ALERT
#Although nte includes an hsearch.c for those who don't have it in
# libc, there's no way to get the default Makefile to build it.
# So we build it here.
pre-build:	work/freebsd/hsearch.o

work/freebsd/hsearch.o:	work/src/hsearch.c
		${CC} -Iwork/src ${CFLAGS} -c -o $@ work/src/hsearch.c

.include <bsd.port.mk>
