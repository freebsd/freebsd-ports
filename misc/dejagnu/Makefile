# New ports collection makefile for:	dejagnu
# Version required:	1.3
# Date created:		12 October 1996
# Whom:			markm
#
# $Id$
#

DISTNAME=	dejagnu-1.3
PKGNAME=	dejagnu-1.3
CATEGORIES+=	devel
MASTER_SITES=	ftp://prep.ai.mit.edu/pub/gnu/

WRKSRC=		${WRKDIR}/${DISTNAME}/dejagnu

MAINTAINER=	markm@FreeBSD.ORG

RUN_DEPENDS=	expect:${PORTSDIR}/lang/expect

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	i386-freebsd --prefix=${PREFIX}
STRIP=

post-install:
.if !defined(NOMANCOMPRESS)
	gzip -9nf ${PREFIX}/man/man1/runtest.1
.endif

.include <bsd.port.mk>
