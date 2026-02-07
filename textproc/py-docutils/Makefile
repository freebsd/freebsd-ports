PORTNAME=	docutils
PORTVERSION=	0.21.2
PORTEPOCH=	1
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python Documentation Utilities
WWW=		https://docutils.sourceforge.io/

LICENSE=	BSD2CLAUSE GPLv3+ PD PSFL
LICENSE_COMB=	multi

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.4<4:devel/py-flit-core@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist concurrent pep517

SHEBANG_FILES=	docutils/writers/odf_odt/prepstyles.py \
		docutils/__main__.py \
		docutils/utils/smartquotes.py \
		docutils/utils/math/math2html.py

NO_ARCH=	yes

PORTSCOUT=	limit:^[0-9\.]*$$

OPTIONS_DEFINE=	PYGMENTS
PYGMENTS_DESC=	Syntax highlighting

PYGMENTS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygments>=0:textproc/py-pygments@${PY_FLAVOR}

do-test:
	cd ${WRKSRC} && ${PYTHON_CMD} test/alltests.py --verbose

.include <bsd.port.mk>
