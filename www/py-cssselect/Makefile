# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cssselect
PORTVERSION=	0.9.1
#PORTREVISION=	0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Cssselect parses CSS3 Selectors and translates them to XPath 1.0

LICENSE=	BSD3CLAUSE

OPTIONS_DEFINE=	DOCS
OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS=	sphinx-build:${PORTSDIR}/textproc/py-sphinx
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
SPHINX_BUILD=	sphinx-build

post-install::
	${SETENV} PYTHONPATH="${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}" \
	${SPHINX_BUILD} -N -a -b html ${WRKSRC}/docs ${WRKSRC}/docs.html
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs.html && \
		${COPYTREE_SHARE:S,\$2,& \! -name .buildinfo -and \! -path *doctrees*,g} \
		. ${STAGEDIR}${DOCSDIR})
.endif

.include <bsd.port.mk>
