# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cssselect
PORTVERSION=	0.9.1
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Cssselect parses CSS3 Selectors and translates them to XPath 1.0

LICENSE=	BSD3CLAUSE

OPTIONS_DEFINE=	DOCS

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
SPHINX_BUILD=	sphinx-build

post-install::
	${SETENV} PYTHONPATH="${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}" \
	${SPHINX_BUILD} -N -a -b html ${WRKSRC}/docs ${WRKSRC}/docs.html
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs.html && \
	${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} "! -name .buildinfo -and ! -path *doctrees*")
.endif

.include <bsd.port.mk>
