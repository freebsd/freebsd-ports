# ex:ts=8
# Ports collection makefile for:  lr
# Date created:                          Tue Jul 14, 2002
# Whom:                                  Michael L. Hostbaek (mich@freebsdcluster.org)
#
# $FreeBSD$
#

PORTNAME=	lr
PORTVERSION=	1.9
CATEGORIES=	misc
MASTER_SITES=	http://www.seekrut.com/rk/
DISTNAME=	lazyread-${PORTVERSION}

MAINTAINER=	mich@freebsdcluster.org
WRKSRC=		${WRKDIR}/${DISTNAME}

do-build:
	cd ${WRKSRC}; ${CC} ${CFLAGS} -o lr lazyread.c -lncurses

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lr ${PREFIX}/bin

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
