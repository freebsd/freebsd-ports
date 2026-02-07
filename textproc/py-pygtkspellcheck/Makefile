PORTNAME=	pygtkspellcheck
PORTVERSION=	5.0.3
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Spellchecking library for GTK written in Python
WWW=		https://pypi.org/project/pygtkspellcheck/ \
		https://github.com/koehlma/pygtkspellcheck

LICENSE=	GPLv3+

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}enchant>=3.0:textproc/py-enchant@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3@${PY_FLAVOR}

USES=		gnome python
USE_GNOME=	gtk30 pygobject3
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>
