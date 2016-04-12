# Created by: Marcin Jessa <yazzy@yazzy.org>
# $FreeBSD$

PORTNAME=	impacket
PORTVERSION=	0.9.14
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP \
		https://github.com/CoreSecurity/impacket/releases/download/impacket_${PORTVERSION:S,.,_,g}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Collection of Python classes providing access to network packets

LICENSE=	APACHE11
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyasn1>=0:devel/py-pyasn1 \
		${PYTHON_PKGNAMEPREFIX}pcapy>=0:net/py-pcapy \
		${PYTHON_PKGNAMEPREFIX}pycrypto>=0:security/py-pycrypto

USES=		dos2unix python
USE_PYTHON=	autoplist distutils

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/impacket && ${COPYTREE_SHARE} testcases ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
