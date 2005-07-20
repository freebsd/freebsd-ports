# ex:ts=8
# Ports collection makefile for:	py-rdflib
# Date created:			Aug 14, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	rdflib
PORTVERSION=	2.1.3
CATEGORIES=	textproc python
MASTER_SITES=	http://rdflib.net/2005/06/28/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Python library for RDF manipulation

USE_PYTHON=	2.2+
USE_PYDISTUTILS=	yes

post-install:
	@${FIND} ${PYTHONPREFIX_SITELIBDIR}/${PORTNAME} ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${PYTHONPREFIX_SITELIBDIR}/${PORTNAME} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
	@${FIND} ${DOCSDIR} ! -type d | ${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${ECHO} "@dirrm ${DOCSDIR:S,${PREFIX}/,,}" >> ${TMPPLIST}
.endif

.include <bsd.port.mk>
