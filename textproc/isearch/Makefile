# New ports collection makefile for:   isearch
# Date created:			21 Sept 1996
# Whom:				Pedro
#
# $FreeBSD$
#

PORTNAME=	isearch
PORTVERSION=	1.47.01
CATEGORIES=	textproc databases
MASTER_SITES=	http://www.etymon.com/pub/Isearch/
DISTNAME=	Isearch-${PORTVERSION}

MAINTAINER=	pmarquis@pobox.com

GNU_CONFIGURE=	yes
MAKE_ARGS=	INSTALL=${PREFIX}/bin

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/html/*.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
