# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	buku
PORTVERSION=	3.6
DISTVERSIONPREFIX=	v
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Powerful command-line bookmark manager

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4.0:www/py-beautifulsoup@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cryptography>=1.3.4:security/py-cryptography@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.0.1:www/py-requests@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>=1.21.1:net/py-urllib3@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${FLAVOR}

USES=		python:3.4+
USE_GITHUB=	yes
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

GH_ACCOUNT=	jarun
GH_PROJECT=	Buku

PLIST_FILES=	man/man1/buku.1.gz

post-install:
	${INSTALL_MAN} ${WRKSRC}/buku.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
