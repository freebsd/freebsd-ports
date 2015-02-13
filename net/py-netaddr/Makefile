# Created by: Yi-Jheng Lin <yzlin@cs.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	netaddr
PORTVERSION=	0.7.13
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Manipulation of IPv4, IPv6, CIDR, EUI and MAC network addresses

LICENSE=	BSD3CLAUSE MIT
LICENSE_COMB=	multi

USES=		python
USE_PYTHON=	autoplist distutils

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}

PORTDOCS=	AUTHORS CHANGELOG README
TESTFILES=	__init__.py

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

regression-test:
.for f in ${TESTFILES}
	(cd ${WRKSRC}/netaddr/tests && ${PYTHON_CMD} $f)
.endfor

.include <bsd.port.mk>
