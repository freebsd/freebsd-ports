PORTNAME=	dash-bootstrap-components
DISTVERSION=	2.0.4
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Bootstrap themed components for use in Plotly Dash
WWW=		https://dash-bootstrap-components.opensource.faculty.ai

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dash>=3.0.4:www/py-dash@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist

NO_ARCH=	yes

post-install:
	${RM} -rf ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/examples
	${RM} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/LICENSE
	${RM} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/NOTICE.txt
	${RM} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/README.md
	${RM} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/pyproject.toml
	@${REINPLACE_CMD} -e '/site-packages\/examples\//d' \
		-e '/site-packages\/LICENSE$$/d' \
		-e '/site-packages\/NOTICE\.txt$$/d' \
		-e '/site-packages\/README\.md$$/d' \
		-e '/site-packages\/pyproject\.toml$$/d' \
		${WRKDIR}/.PLIST.pymodtmp

.include <bsd.port.mk>
