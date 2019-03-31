# $FreeBSD$

PORTNAME=	tablib
DISTVERSION=	0.13.0
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Format agnostic tabular data library (XLS, JSON, YAML, CSV)

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}odfpy>0:devel/py-odfpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openpyxl>=2.4.0:textproc/py-openpyxl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xlrd>0:textproc/py-xlrd@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xlwt>0:textproc/py-xlwt@${PY_FLAVOR}

py27_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}backports.csv>0:devel/py-backports.csv@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes
SUB_FILES=	pkg-message
SUB_LIST=	PYTHON_PKGNAMEPREFIX=${PYTHON_PKGNAMEPREFIX}

post-patch:
	@${REINPLACE_CMD} -Ee 's|(backports\.csv)|\1;python_version<"3.0"|' \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
