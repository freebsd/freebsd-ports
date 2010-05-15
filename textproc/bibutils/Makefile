# New ports collection makefile for:	bibutils
# Date created:		May 14, 2010
# Whom:			Gabor Pali <pgj@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bibutils
PORTVERSION=	4.9
CATEGORIES=	textproc
MASTER_SITES=	http://www.scripps.edu/~cdputnam/software/bibutils/
DISTNAME=	${PORTNAME}_${PORTVERSION}_src
EXTRACT_SUFX=	.tgz

MAINTAINER=	pgj@FreeBSD.org
COMMENT=	Program set interconverts between various bibliography formats

USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} 's|make |gmake |g' \
		${WRKSRC}/Makefile_start

do-configure:
	@cd ${WRKSRC} && ./configure --install-dir ${PREFIX}/bin

test: all
	cd ${WRKSRC}/test && ${GMAKE} all test

.include <bsd.port.mk>
