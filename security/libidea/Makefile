# New ports collection makefile for:	libidea
# Date created:				Sep 30, 2002
# Whom:					Jim Geovedi <jim@corebsd.or.id>
#
# $FreeBSD$
#

PORTNAME=	libidea
PORTVERSION=	0.8.2b
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.funet.fi/pub/mirrors/ftp.psy.uq.oz.au/libeay/ \
		ftp://ftp.psy.uq.oz.au/pub/Crypto/libeay/ \
		ftp://ftp.ntnu.no/pub/unix/security/ \
		ftp://ftp.sunsite.org.uk/Mirrors/ftp.psy.uq.oz.au/pub/Crypto/libeay/

MAINTAINER=	jim@corebsd.or.id
COMMENT=	IDEA block cipher library

RESTRICTED=	"Crypto; IDEA is a patented algorithm that requires proper licensing"

WRKSRC=		${WRKDIR}/idea

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ideatest ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/idea_spd ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/libidea.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/idea.h ${PREFIX}/include

.include <bsd.port.mk>
