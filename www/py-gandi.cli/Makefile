PORTNAME=	gandi.cli
PORTVERSION=	1.6
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Gandi command line interface
WWW=		https://github.com/Gandi/gandi.cli

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Upstream no longer continuing
# Should be removed along with python38
EXPIRATION_DATE=	2024-10-31

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=7.0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipy>0:net-mgmt/py-ipy@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} > 30900
BROKEN=		python-3.9 is not supported
.endif

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest -v -rs

.include <bsd.port.post.mk>
