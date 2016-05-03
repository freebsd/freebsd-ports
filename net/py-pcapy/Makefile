# Created by: Marcin Jessa <yazzy@yazzy.org>
# $FreeBSD$

PORTNAME=	pcapy
PORTVERSION=	0.10.9
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python pcap extension

LICENSE=	APACHE11
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:2
USE_PYTHON=	autoplist distutils

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
PORTDOCS=	README pcapy.html

OPTIONS_DEFINE=	DOCS

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/pcapy.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
