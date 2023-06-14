PORTNAME=	impacket
PORTVERSION=	0.9.17
PORTREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	PYPI \
		https://github.com/CoreSecurity/impacket/releases/download/impacket_${PORTVERSION:S,.,_,g}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	contato@kanazuchi.com
COMMENT=	Collection of Python classes providing access to network packets
WWW=		https://www.coresecurity.com/corelabs-research/open-source-tools/impacket

LICENSE=	APACHE11 ZLIB
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyasn1>=0:devel/py-pyasn1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pcapy>=0:net/py-pcapy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycryptodome>0:security/py-pycryptodome@${PY_FLAVOR}

USES=		dos2unix python
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} tests ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
