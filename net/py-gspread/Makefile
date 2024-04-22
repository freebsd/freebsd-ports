PORTNAME=	gspread
PORTVERSION=	6.1.0
DISTVERSIONPREFIX=	v
CATEGORIES=	net python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Google Spreadsheets Python API
WWW=		http://burnash.github.io/gspread/

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>0:devel/py-flit-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>2.2.1:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-auth>1.12.0:security/py-google-auth@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-auth-oauthlib>0.4.1:security/py-google-auth-oauthlib@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist

NO_ARCH=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	burnash

.include <bsd.port.mk>
