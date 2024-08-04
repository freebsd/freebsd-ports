PORTNAME=	tqdm
PORTVERSION=	4.66.5
CATEGORIES=	misc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fast, extensible progress bar for Python
WWW=		https://tqdm.github.io/ \
		https://github.com/tqdm/tqdm

LICENSE=	MIT MPL20
LICENSE_COMB=	multi
LICENSE_FILE_MIT=	${WRKSRC}/LICENCE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=42:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=3.4:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		cpe python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

CPE_VENDOR=	tqdm_project

OPTIONS_DEFINE=	NOTEBOOK SLACK TELEGRAM
NOTEBOOK_DESC=	Notebook support
SLACK_DESC=	Slack support
TELEGRAM_DESC=	Telegram support

NOTEBOOK_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ipywidgets>=6:devel/py-ipywidgets@${PY_FLAVOR}
SLACK_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}slack-sdk>=0:net-im/py-slack-sdk@${PY_FLAVOR}
TELEGRAM_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR}

.include <bsd.port.mk>
