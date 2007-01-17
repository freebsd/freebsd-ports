# Ports collection makefile for:	simlib
# Whom:					Pav Lucistnik <pav@FreeBSD.org>
# Date created:				26 Nov 2004
#
# $FreeBSD$
#

PORTNAME=	simlib
PORTVERSION=	2.18.20061212
CATEGORIES=	science
MASTER_SITES=	http://www.fit.vutbr.cz/~peringer/SIMLIB/source/
DISTNAME=	SIMLIB-${PORTVERSION:S/.200/-200/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SIMulation LIBrary for C++ programming language

NO_WRKSUBDIR=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
MAKEFILE=	Makefile.FreeBSD

# not 64bit ready
ONLY_FOR_ARCHS=	i386

.include <bsd.port.mk>
