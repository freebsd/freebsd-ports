# Created by: M. Warner Losh <imp@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dlipower
PORTVERSION=	20151118
CATEGORIES=	sysutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	imp@FreeBSD.org
COMMENT=	CLI interface to Digital Logger's (DLI) Power Strips

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4.0:${PORTSDIR}/www/py-beautifulsoup \
		${PYTHON_PKGNAMEPREFIX}requests>=2.0:${PORTSDIR}/www/py-requests

USE_GITHUB=	yes
GH_ACCOUNT=	dwighthubbard
GH_PROJECT=	python-dlipower
GH_TAGNAME=	9c3bb94

USES=		python
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

.include <bsd.port.mk>
