PORTNAME=	doclang
PORTVERSION=	0.9.0
CATEGORIES=	textproc python # machine-learning
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DocLang reference toolkit
WWW=		https://doclang.ai/ \
		https://github.com/doclang-project

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=6.0.2:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typer>=0.15.1:devel/py-typer@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517
NO_ARCH=	yes

post-extract:
	@${REINPLACE_CMD} -e 's/^license = "\([^"]*\)"/license = {text = "\1"}/' \
		-e '/^license-files/d' \
		-e 's/setuptools>=80/setuptools>=0/' \
		${WRKSRC}/pyproject.toml

.include <bsd.port.mk>
