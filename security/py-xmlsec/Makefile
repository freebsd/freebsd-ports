# ex:ts=8
# Ports collection makefile for:	pyxmlsec
# Date created:			Feb 3, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	xmlsec
PORTVERSION=	0.2.1
CATEGORIES=	security python
MASTER_SITES=	http://pyxmlsec.labs.libre-entreprise.org/releases/sources/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A set of Python bindings for XML Security Library

LIB_DEPENDS=	xmlsec1.3:${PORTSDIR}/security/xmlsec1

USE_PYTHON=	2.2+
USE_PYDISTUTILS=	yes

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

post-install:
	@${FIND} ${PYTHONPREFIX_SITELIBDIR} -name "xmlsec*" | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/docs/html/* ${DOCSDIR}
	@${FIND} ${DOCSDIR} -type f | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${DOCSDIR} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}

	@${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/* ${EXAMPLESDIR}
	@${FIND} ${EXAMPLESDIR} -type f | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${EXAMPLESDIR} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
.endif

.include <bsd.port.mk>
