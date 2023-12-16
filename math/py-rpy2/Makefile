PORTNAME=	rpy2
PORTVERSION=	3.5.14
PORTREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python interface to the R Programming Language
WWW=		https://rpy2.github.io/ \
		https://github.com/rpy2/rpy2

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/gpl-2.0.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=1.10.0:devel/py-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=61:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libR.so:math/R \
		libicui18n.so:devel/icu \
		libpcre2-8.so:devel/pcre2
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=1.10.0:devel/py-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tzlocal>=0:devel/py-tzlocal@${PY_FLAVOR}

USES=		compiler:c11 fortran python readline
USE_PYTHON=	autoplist concurrent pep517

MAKE_ENV=	RPY2_CFFI_MODE=BOTH

OPTIONS_DEFINE=	PANDAS
OPTIONS_DEFAULT=PANDAS
PANDAS_DESC=	Pandas support

PANDAS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=0,1:math/py-numpy@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pandas>=1.3.5,1:math/py-pandas@${PY_FLAVOR}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30900
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}backports.zoneinfo>=0:devel/py-backports.zoneinfo@${PY_FLAVOR}
.endif

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.post.mk>
