# New ports collection makefile for:	GLPK
# Date created:		16 December 2000
# Whom:			Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	glpk
PORTVERSION=	4.4
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	glpk

MAINTAINER=	demon@FreeBSD.org
COMMENT=	A GNU Linear Programming Kit

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

DOCFILES=	lang.ps refman.ps bench.txt GLPK_FAQ.txt

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	for file in ${DOCFILES} ; do \
		${INSTALL_DATA} ${WRKSRC}/doc/$$file ${DOCSDIR} ; \
	done
.endif

.include <bsd.port.mk>
