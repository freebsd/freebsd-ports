# New ports collection makefile for:	nte
# Version required:			1.5a23
# Date created:				5 September 1996
# Whom:	      Bill Fenner <fenner@FreeBSD.ORG>
#
#   $Id: Makefile,v 1.8 1998/08/05 09:31:31 asami Exp $
#

DISTNAME=	nt.1.5a23
PKGNAME=	nte-1.5a23
CATEGORIES=	mbone tk42
MASTER_SITES=	ftp://cs.ucl.ac.uk/mice/nte/

MAINTAINER=	fenner@FreeBSD.org

TK_DIR=         ${PORTSDIR}/x11-toolkits/tk42
TK_SRC=		${TK_DIR}/work/tk4.2p2

DEPENDS=	${TK_DIR}
LIB_DEPENDS=	tk42\\.1:${TK_DIR}

RESTRICTED=	"Contains DES encryption"
NO_WRKSUBDIR=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
# Pass this on to our child
MAKE_ENV=	TK_SRC=${TK_SRC}

.include <bsd.port.mk>

#DISGUSTING HACK ALERT
#Although nte includes an hsearch.c for those who don't have it in
# libc, there's no way to get the default Makefile to build it.
# So we build it here.
#This is below the .include <bsd.port.mk> since variable names in
# targets or dependencies are evaluated when they are read so
# bsd.port.mk must have defined ${WRKSRC} already.
pre-build:	${WRKSRC}/freebsd/hsearch.o

${WRKSRC}/freebsd/hsearch.o:	${WRKSRC}/src/hsearch.c
		${CC} -I${WRKSRC}/src ${CFLAGS} -c -o $@ ${WRKSRC}/src/hsearch.c
