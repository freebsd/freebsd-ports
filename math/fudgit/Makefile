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
MASTER_SITES=	ftp://ftp.physics.mcgill.ca/pub/Fudgit/
DISTNAME=	Fudgit_${PORTVERSION}
DISTFILES=	fudgit_${PORTVERSION}.tar.gz

MAINTAINER=	jmz@FreeBSD.org
COMMENT=	Multi-purpose data-processing and fitting program

USE_GMAKE=	yes
MAN1=		fudgit.1

pre-install:
	@${MKDIR} ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/lib/fudgit
	@${MKDIR} ${PREFIX}/man/man1
	@(cd ${WRKSRC}/examples; ${CP} * ${PREFIX}/lib/fudgit)

.include <bsd.port.mk>
