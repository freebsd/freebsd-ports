# Created by: Yuri Victorovich
# $FreeBSD$

PORTNAME=	txtorcon
DISTVERSION=	19.1.0
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Twisted-based Tor controller client

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}twisted>=15.5.0:devel/py-twisted@${PY_FLAVOR} \
		${PY_IPADDRESS} \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=3.6.1:devel/py-zope.interface@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}incremental>0:devel/py-incremental@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Automat>0:devel/py-Automat@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes
SHEBANG_FILES=	examples/*.py

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

.include <bsd.port.mk>
