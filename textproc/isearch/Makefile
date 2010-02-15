# New ports collection makefile for:   isearch
# Date created:			21 Sept 1996
# Whom:				Pedro Giffuni
#
# $FreeBSD$
#

PORTNAME=	isearch
PORTVERSION=	1.47i
PORTREVISION=	1
CATEGORIES=	textproc databases
MASTER_SITES=	http://www.etymon.com/software/Isearch/
DISTNAME=	Isearch-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Text Search Engine by CNIDR

DEPRECATED=	abandoned upstream, uses an obsolete version of GCC, not used by any other port
EXPIRATION_DATE=2010-03-15

USE_GCC=	3.4
CFLAGS+=	-fwritable-strings

MAKE_ARGS=	INSTALL=${PREFIX}/bin

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/html/*.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
