# Created by: Yi-Jheng Lin <yzlin@cs.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	netaddr
PORTVERSION=	0.7.14
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Manipulation of IPv4, IPv6, CIDR, EUI and MAC network addresses

LICENSE=	BSD3CLAUSE MIT
LICENSE_COMB=	multi

NO_ARCH=	yes

USES=		python
USE_PYTHON=	autoplist distutils uniquefiles:dirs

PORTDOCS=	AUTHORS CHANGELOG README

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
