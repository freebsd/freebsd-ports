# New ports collection makefile for:	GLPK
# Date created:		16 December 2000
# Whom:			Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	glpk
PORTVERSION=	3.0.5
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GNU} \
		http://people.freebsd.org/~demon/distfiles/
MASTER_SITE_SUBDIR=	glpk

MAINTAINER=	demon@FreeBSD.org

.if !defined(NOPORTDOCS)
BUILD_DEPENDS=	texi2dvi:${PORTSDIR}/print/teTeX
.endif

GNU_CONFIGURE=	yes

DOCFILES=	guide language libref simplex

post-build:
.if !defined(NOPORTDOCS)
	for file in ${DOCFILES} ; do \
		cd ${WRKSRC} && ${LOCALBASE}/bin/texi2dvi doc/$$file.texinfo ; \
		${LOCALBASE}/bin/dvips -o ${WRKSRC}/$$file.ps \
		${WRKSRC}/$$file.dvi ; \
	done
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	for file in ${DOCFILES} ; do \
		${INSTALL_DATA} ${WRKSRC}/$$file.ps ${DOCSDIR} ; \
	done
.endif

.include <bsd.port.mk>
