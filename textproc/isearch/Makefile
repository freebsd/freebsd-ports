# New ports collection makefile for:   isearch
# Date created:			21 Sept 1996
# Whom:				Pedro
#
# $FreeBSD$
#

PORTNAME=	isearch
PORTVERSION=	1.47i
CATEGORIES=	textproc databases
MASTER_SITES=	http://www.etymon.com/software/Isearch/
DISTNAME=	Isearch-${PORTVERSION}

MAINTAINER=	pmarquis@pobox.com
COMMENT=	Text Search Engine by CNIDR

GNU_CONFIGURE=	yes
MAKE_ARGS=	INSTALL=${PREFIX}/bin

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/html/*.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
