# New ports collection makefile for:	cksfv
# Date created:		18 October 2000
# Whom:	      		Johann Visagie <johann@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	cksfv
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.fodder.org/cksfv/

MAINTAINER=	wjv@FreeBSD.org
COMMENT=	Create or manipulate Simple File Verification (SFV) checksum files

BUILD_WRKSRC=	${WRKSRC}/src
INSTALL_WRKSRC=	${BUILD_WRKSRC}
USE_GMAKE=	yes
ALL_TARGET=	${PORTNAME}
MAKE_ENV+=	VERSION=${PORTVERSION}

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/cksfv
	@ ${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/cksfv
.endif

.include <bsd.port.mk>
