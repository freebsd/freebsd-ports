# New ports collection Makefile for:		memgrep
# Date created:					22 February 2003
# Whom:						Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	memgrep
PORTVERSION=	0.7.0
CATEGORIES=	sysutils
MASTER_SITES=	http://www.hick.org/code/skape/memgrep/

MAINTAINER=	sheepkiller@cultdeadsheep.org
COMMENT=	Utility to manipulate memory from running processes and core files

HAS_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

ONLY_FOR_ARCHS=	i386

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/docs/html/* ${DOCSDIR}/html
.endif

.include <bsd.port.mk>
