# Created by: Marcin Jessa <yazzy@yazzy.org>
# $FreeBSD$

PORTNAME=	pcapy
PORTVERSION=	0.10.8
CATEGORIES=	net python
MASTER_SITES=	http://corelabs.coresecurity.com/index.php?module=Wiki&action=attachment&type=tool&page=Pcapy&file=
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python extension module to capture packets on the network

LICENSE=	AL11
LICENSE_NAME=	Apache License version 1.1
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

FETCH_BEFORE_ARGS=-o ${DISTFILES}
USES=		dos2unix python
USE_PYTHON=	distutils

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/pcapy.so
PORTDOCS=	README pcapy.html


post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
