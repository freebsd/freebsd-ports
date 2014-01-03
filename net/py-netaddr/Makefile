# Created by: Yi-Jheng Lin <yzlin@cs.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	netaddr
PORTVERSION=	0.7.10
CATEGORIES=	net python
MASTER_SITES=	https://github.com/downloads/drkjam/netaddr/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python library for the manipulation of network addresses

LICENSE=	BSD

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

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
