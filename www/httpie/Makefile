# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	httpie
PORTVERSION=	0.9.3
CATEGORIES=	www

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Command line HTTP client

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests \
		${PYTHON_PKGNAMEPREFIX}pygments>0:textproc/py-pygments

USE_GITHUB=	yes
GH_ACCOUNT=	jakubroztocil

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
