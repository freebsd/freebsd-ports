# New ports collection makefile for:    Fudgit
# Version required:     2.41
# Date created:         17 November 1994
# Whom:                 jmz
#
# $FreeBSD$
#

DISTNAME=	Fudgit_2.41
PKGNAME=	Fudgit-2.41
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.physics.mcgill.ca/pub/Fudgit/
DISTFILES=	fudgit_2.41.tar.gz

MAINTAINER=	jmz@FreeBSD.org

USE_GMAKE=	yes
MAN1=		fudgit.1

pre-install:
	@${MKDIR} ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/lib/fudgit
	@${MKDIR} ${PREFIX}/man/man1
	@(cd ${WRKSRC}/examples; ${CP} * ${PREFIX}/lib/fudgit)

.include <bsd.port.mk>
