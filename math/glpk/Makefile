# New ports collection makefile for:	GLPK
# Date created:		16 December 2000
# Whom:			Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	glpk
PORTVERSION=	3.2
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	glpk

MAINTAINER=	demon@FreeBSD.org

BROKEN=		"Does not install"

GNU_CONFIGURE=	yes

DOCFILES=	lang refman

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	for file in ${DOCFILES} ; do \
		${INSTALL_DATA} ${WRKSRC}/$$file.ps ${DOCSDIR} ; \
	done
.endif

.include <bsd.port.mk>
