PORTNAME=	mkdocs-rss-plugin
DISTVERSION=	1.15.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Generates a static RSS feed using git log and page.meta
WWW=		https://github.com/Guts/mkdocs-rss-plugin

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cachecontrol>=0.14<1:www/py-cachecontrol@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gitpython>=3.1<3.2:devel/py-gitpython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.31<3:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mkdocs>=1.4.1:textproc/py-mkdocs@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	Guts
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30900
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pytz>=2024,1:devel/py-pytz@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
