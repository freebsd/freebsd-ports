# New ports collection makefile for:	nte
# Version required:			1.5a23
# Date created:				5 September 1996
# Whom:	      Bill Fenner <fenner@FreeBSD.ORG>
#
#   $Id: Makefile,v 1.11 1998/09/21 23:39:42 fenner Exp $
#

DISTNAME=	nte-1.5a29
CATEGORIES=	mbone tk80
MASTER_SITES=	http://www-mice.cs.ucl.ac.uk/multimedia/software/nte/1.5a29/

MAINTAINER=	fenner@FreeBSD.org

LIB_DEPENDS=	tk80.1:${PORTSDIR}/x11-toolkits/tk80

WRKSRC=		${WRKDIR}/nte

RESTRICTED=	"Contains DES encryption"
USE_GMAKE=	yes
USE_X_PREFIX=	yes

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
