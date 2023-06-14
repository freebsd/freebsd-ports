PORTNAME=	portgraph
PORTVERSION=	0.0.1
CATEGORIES=	ports-mgmt python
MASTER_SITES=	PYPI

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	Create a dependencies graph of a(all) port(s)
WWW=		https://gitlab.com/lbartoletti/portgraph

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}graphviz>=0.8.2:graphics/py-graphviz@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist noflavors
NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} \
		-e 's|/usr/ports|${PORTSDIR}| ; s|ports-mgmt/py-portgraph|ports-mgmt/portgraph|' \
		${WRKSRC}/portgraph/portgraph.py

.include <bsd.port.mk>
