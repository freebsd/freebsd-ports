# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	buku
PORTVERSION=	3.5
DISTVERSIONPREFIX=	v
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Powerful command-line bookmark manager

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4.0:www/py-beautifulsoup \
		${PYTHON_PKGNAMEPREFIX}cryptography>=1.3.4:security/py3-cryptography \
		${PYTHON_PKGNAMEPREFIX}requests>=2.0.1:www/py3-requests \
		${PYTHON_PKGNAMEPREFIX}urllib3>=1.21.1:net/py3-urllib3 \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py${PYTHON_SUFFIX}-sqlite3

USES=		python:3
USE_GITHUB=	yes
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

GH_ACCOUNT=	jarun
GH_PROJECT=	Buku

PLIST_FILES=	man/man1/buku.1.gz

.include <bsd.port.pre.mk>

.if defined(PACKAGE_BUILDING) && !defined(PACKAGE_BUILDING_FLAVORS) && \
	${PYTHON_VER} != ${PYTHON_DEFAULT}
IGNORE=	you have python ${PYTHON_DEFAULT} set as the default, and this needs ${PYTHON_VER}
.endif

post-install:
	${INSTALL_MAN} ${WRKSRC}/buku.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.post.mk>
