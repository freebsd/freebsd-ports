# New ports collection makefile for:    Fudgit
# Version required:     2.41
# Date created:         17 November 1994
# Whom:                 jmz
#
# $Id: Makefile,v 1.4 1995/04/11 02:00:55 jmz Exp $
#

DISTNAME=	Fudgit_2.41
PKGNAME=	Fudgit-2.41
MASTER_SITES=	ftp://ftp.physics.mcgill.ca/pub/Fudgit/
DISTFILES=	fudgit_2.41.tar.gz

MAINTAINER=	jmz@FreeBSD.org

USE_GMAKE=	yes

pre-install:
	@mkdir -p ${PREFIX}/bin
	@mkdir -p ${PREFIX}/lib/fudgit
	@mkdir -p ${PREFIX}/man/man1
	@(cd ${WRKSRC}/examples; cp * ${PREFIX}/lib/fudgit)

.include <bsd.port.mk>
