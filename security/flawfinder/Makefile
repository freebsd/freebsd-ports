# ex:ts=8
# New ports collection makefile for:	flawfinder
# Date created:			Jul 23, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	flawfinder
PORTVERSION=	1.22
CATEGORIES=	security devel
MASTER_SITES=	${MASTER_SITE_PACKETSTORM} \
		http://www.dwheeler.com/flawfinder/
MASTER_SITE_SUBDIR=	UNIX/security

MAINTAINER=	jim@corebsd.or.id
COMMENT=	Examines source code looking for security weaknesses

USE_PYTHON=	yes
NO_BUILD=	yes

MAN1=	flawfinder.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/flawfinder ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/flawfinder.1 ${MANPREFIX}/man/man1

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in README flawfinder.pdf flawfinder.ps index.html test.c
	${INSTALL_DATA} ${WRKSRC}/$i ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
