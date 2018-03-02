# Created by: Carlo Strub
# $FreeBSD$

PORTNAME=	nyx
PORTVERSION=	2.0.4
PORTREVISION=	1
CATEGORIES=	security net
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Command-line monitor for Tor

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}stem>=1.6.0:security/py-stem@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

PLIST_FILES=	man/man1/nyx.1.gz

post-install:
		${INSTALL_MAN} ${WRKSRC}/nyx.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
