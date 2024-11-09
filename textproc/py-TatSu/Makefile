PORTNAME=	TatSu
DISTVERSIONPREFIX=	v
DISTVERSION=	5.12.2
CATEGORIES=	textproc python
MASTER_SITES=	PYPI

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Generate Python parsers from grammars in a variation of EBNF
WWW=		https://tatsu.readthedocs.io/en/stable/ \
		https://github.com/neogeny/TatSu

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		python:3.11+
USE_PYTHON=	pep517 concurrent autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	neogeny

NO_ARCH=	yes

POST_PLIST+=	fix-plist

post-install: # workaround https://github.com/neogeny/TatSu/issues/333
	@${RM} -r ${STAGEDIR}${PYTHON_SITELIBDIR}/test

fix-plist:
	${REINPLACE_CMD} -e 's|^.*/test/.*$$||' ${TMPPLIST}

# tests as of version 5.12.2: 1 failed, 137 passed, 2 skipped in 337.83s (0:05:37), see https://github.com/neogeny/TatSu/issues/348

.include <bsd.port.mk>
