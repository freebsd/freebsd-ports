# ex:ts=8
# Ports collection makefile for:	py-rdflib
# Date created:			Aug 14, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	rdflib
PORTVERSION=	2.0.4
CATEGORIES=	textproc python
MASTER_SITES=	http://rdflib.net/2004/10/14/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Python library for RDF manipulation

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

post-install:
	@${FIND} ${PYTHON_SITELIBDIR}/${PORTNAME} ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${PYTHON_SITELIBDIR}/${PORTNAME} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}

.include <bsd.port.mk>
