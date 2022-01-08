# Created by: Yi-Jheng Lin <yzlin@cs.nctu.edu.tw>

PORTNAME=	netaddr
PORTVERSION=	0.8.0
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Manipulation of IPv4, IPv6, CIDR, EUI and MAC network addresses

LICENSE=	BSD3CLAUSE MIT
LICENSE_COMB=	multi

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=2.4.2:devel/py-pytest@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

PORTDOCS=	AUTHORS CHANGELOG README.rst

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

do-test:
	@cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest -v -rs

.include <bsd.port.mk>
