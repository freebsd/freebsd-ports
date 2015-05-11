# Created by: Marcin Jessa <yazzy@yazzy.org>
# $FreeBSD$

PORTNAME=	impacket
PORTVERSION=	0.9.13
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP \
		https://github.com/CoreSecurity/impacket/releases/download/impacket_${PORTVERSION:S,.,_,g}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Collection of Python classes providing access to network packets

LICENSE=	APACHE11
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}asn1>=0:${PORTSDIR}/devel/py-asn1 \
		${PYTHON_PKGNAMEPREFIX}pcapy>=0:${PORTSDIR}/net/py-pcapy \
		${PYTHON_PKGNAMEPREFIX}pycrypto>=0:${PORTSDIR}/security/py-pycrypto

USES=		dos2unix python
USE_PYTHON=	distutils autoplist

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/impacket && ${COPYTREE_SHARE} testcases ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
