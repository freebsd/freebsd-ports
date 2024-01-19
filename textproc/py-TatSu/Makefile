PORTNAME=	TatSu
DISTVERSION=	5.11.3
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Generate Python parsers from grammars in a variation of EBNF
WWW=		https://tatsu.readthedocs.io/en/stable/

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		python:3.11+
USE_PYTHON=	pep517 concurrent autoplist

NO_ARCH=	yes

POST_PLIST+=		fix-plist

post-install: # workaround https://github.com/neogeny/TatSu/issues/333
	@${RM} -r ${STAGEDIR}${PYTHON_SITELIBDIR}/test

fix-plist:
	${REINPLACE_CMD} -e 's|^.*/test/.*$$||' ${TMPPLIST}

.include <bsd.port.mk>
