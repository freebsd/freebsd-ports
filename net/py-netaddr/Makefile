# Created by: Yi-Jheng Lin <yzlin@cs.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	netaddr
PORTVERSION=	0.7.18
PORTREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Manipulation of IPv4, IPv6, CIDR, EUI and MAC network addresses

LICENSE=	BSD3CLAUSE MIT
LICENSE_COMB=	multi

USES=		python shebangfix
USE_PYTHON=	autoplist concurrent distutils
SHEBANG_FILES=	netaddr/tools/netaddr
NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS

PORTDOCS=	AUTHORS CHANGELOG README.md

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
