PORTNAME=	netaddr
PORTVERSION=	0.10.1
CATEGORIES=	net python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Manipulation of IPv4, IPv6, CIDR, EUI and MAC network addresses
WWW=		https://github.com/drkjam/netaddr/

LICENSE=	BSD3CLAUSE MIT
LICENSE_COMB=	multi

USES=		python
USE_PYTHON=	autoplist concurrent distutils pytest

NO_ARCH=	yes

PORTDOCS=	AUTHORS CHANGELOG README.rst

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
