# New ports collection makefile for: br-ispell
# URL: http://www.ime.usp.br/~ueda/br.ispell/
# Version required:     2.2
# Date created:         5 February 1999
# Whom:                 Joao Carlos Mendes Luis <jonny@jonny.eng.br>
#
# $FreeBSD$
#

DISTNAME=	br.ispell-2.2
PKGNAME=	br-ispell-2.2
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.ime.usp.br/pub/ueda/br.ispell/

MAINTAINER=	jonny@jonny.eng.br

BUILD_DEPENDS=	buildhash:${PORTSDIR}/textproc/ispell

NO_WRKSUBDIR=	YES

pre-build:
	@${CP} ${FILESDIR}/Makefile ${WRKDIR}

.include <bsd.port.mk>
