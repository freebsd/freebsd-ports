# ex:ts=8
# New ports collection makefile for:	newmat
# Date created:			Dec 6, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	newmat
PORTVERSION=	1.0
CATEGORIES=	math
MASTER_SITES=	ftp://webnz.com/robert/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}

MAINTAINER=	ports@FreeBSD.org

NO_WRKSUBDIR=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
MAKEFILE=	nm_gnu.mak
ALL_TARGET=	everything

post-patch:
	@${REINPLACE_CMD} -e "s,^CXX,#CXX,g ; \
		s,^CXXFLAGS,#CXXFLAGS,g" ${WRKSRC}/${MAKEFILE}

do-install:
	@${MKDIR} ${PREFIX}/include/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/*.h ${PREFIX}/include/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/libnewmat.a ${PREFIX}/lib

.include <bsd.port.mk>
