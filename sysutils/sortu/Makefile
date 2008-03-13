# New ports collection makefile for:	sortu
# Date created:		Wed Mar 12 18:13:34 PDT 2008
# Whom:			Matt Peterson <matt@peterson.org>
#
# $FreeBSD$
#

PORTNAME=	sortu
PORTVERSION=	2.1.0
CATEGORIES=	sysutils
MASTER_SITES=	http://256.com/sources/sortu/ \
		http://matt.peterson.org/FreeBSD/ports/
EXTRACT_SUFX=	.tgz

MAINTAINER=	matt@peterson.org
COMMENT=	Tool that combines sort and uniq functionality

ALL_TARGET=	sortu

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sortu ${PREFIX}/bin

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
