# New ports collection makefile for:	GLPK
# Date created:		16 December 2000
# Whom:			Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	glpk
PORTVERSION=	2.2
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GNU} \
		http://people.freebsd.org/~demon/distfiles/
MASTER_SITE_SUBDIR=	glpk
.if !defined(NOPORTDOCS)
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DOCFILES}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
.endif

MAINTAINER=	demon@FreeBSD.org

GNU_CONFIGURE=	yes

DOCFILES=	glpk_lr-1.1.1.ps.gz glpk_sm.ps.gz glpk_ug-1.1.1.ps.gz

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/glpk
	for file in ${DOCFILES} ; do \
		${INSTALL_DATA} ${DISTDIR}/$$file ${PREFIX}/share/doc/glpk/ ; \
		${GUNZIP_CMD} ${PREFIX}/share/doc/glpk/$$file ; \
	done
.endif

.include <bsd.port.mk>
