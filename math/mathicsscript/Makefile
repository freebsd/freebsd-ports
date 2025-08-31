PORTNAME=	mathicsscript
PORTVERSION=	8.0.0
PORTREVISION=	3
CATEGORIES=	math python
MASTER_SITES=	PYPI

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Terminal CLI to Mathics
WWW=		https://mathics.org/

LICENSE=	GPLv3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Mathics3>0:math/py-mathics \
		${PYTHON_PKGNAMEPREFIX}mathics_pygments>0:textproc/py-mathics-pygments \
		${PYTHON_PKGNAMEPREFIX}click>0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>0:math/py-networkx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorama>0:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}columnize>0:devel/py-columnize@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>0:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prompt-toolkit>0:devel/py-prompt-toolkit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}term-background>0:deskutils/py-term-background@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Mathics3>0:math/py-mathics \
		${PYTHON_PKGNAMEPREFIX}mathics_pygments>0:textproc/py-mathics-pygments \
		${PYTHON_PKGNAMEPREFIX}qt6>0:devel/py-qt6@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cson>0:devel/py-cson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyaml>0:textproc/py-pyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>2.5:math/py-networkx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorama>0:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}columnize>0:devel/py-columnize@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>0:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cairosvg>0:graphics/py-cairosvg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prompt-toolkit>0:devel/py-prompt-toolkit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}term-background>0:deskutils/py-term-background@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

#USE_GITHUB=	yes
#GH_ACCOUNT=	Mathics3

USES=		python readline shebangfix
USE_PYTHON=	distutils noflavors
SHEBANG_GLOB=	*.py

MAKE_ENV+=	PYTHON=${PYTHON_CMD}
NO_ARCH=	yes

post-stage:
	${RM} -r ${STAGEDIR}/${PYTHON_SITELIBDIR}/test

.include <bsd.port.mk>
