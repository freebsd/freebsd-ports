# New ports collection makefile for:    Fudgit
# Date created:         17 November 1994
# Whom:                 jmz
#
# $FreeBSD$
#

PORTNAME=	Fudgit
PORTVERSION=	2.41
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://ftp.chg.ru/pub/math/Fudgit/
DISTFILES=	fudgit_${PORTVERSION}.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multi-purpose data-processing and fitting program

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

USE_GMAKE=	yes
MAN1=		fudgit.1
WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION}

pre-install:
	@${MKDIR} ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/lib/fudgit
	@${MKDIR} ${PREFIX}/man/man1
	@(cd ${WRKSRC}/examples; ${CP} * ${PREFIX}/lib/fudgit)

.include <bsd.port.mk>
