PORTNAME=	txtorcon
DISTVERSION=	24.8.0
PORTREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Twisted-based Tor controller client
WWW=		https://github.com/meejah/txtorcon

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Automat>0:devel/py-Automat@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}incremental>0:devel/py-incremental@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}twisted>=15.5.0:devel/py-twisted@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=3.6.1:devel/py-zope.interface@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist cryptography distutils pytest # 1 test fails, see https://github.com/meejah/txtorcon/issues/376

SHEBANG_FILES=	examples/*.py

NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e " \
		s|'share/txtorcon'|'${DOCSDIR}'| ; \
		s|'share/txtorcon/examples'|'${EXAMPLESDIR}'|" \
		${WRKSRC}/setup.py

post-patch-DOCS-off:
	@${REINPLACE_CMD} -E " \
		s|(.*'${DOCSDIR}'.*)|#\1| ; \
		s|(.*'docs/.*',$$)|#\1| ; \
		s|(.*\+ sphinx_docs.*)|#\1|" \
		${WRKSRC}/setup.py

post-patch-EXAMPLES-off:
	@${REINPLACE_CMD} -E "s|(.*'${EXAMPLESDIR}'.*)|#\1|" ${WRKSRC}/setup.py

# tests as of 24.8.0: 1 failed, 679 passed, 2 skipped, 662 warnings in 195.73s (0:03:15)

.include <bsd.port.mk>
