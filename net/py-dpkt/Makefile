PORTNAME=	dpkt
PORTVERSION=	1.9.6
CATEGORIES=	net python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Python fast, simple packet creation / parsing module
WWW=		https://github.com/kbandla/dpkt

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python
USE_PYTHON=	autoplist concurrent distutils pythonprefix

NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS

PORTDOCS=	AUTHORS CHANGES PKG-INFO README.rst

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
