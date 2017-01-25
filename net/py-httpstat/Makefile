# Created by: Danilo G. Baio <dbaio@bsd.com.br>
# $FreeBSD$

PORTNAME=	httpstat
PORTVERSION=	1.2.1
CATEGORIES=	net python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dbaio@bsd.com.br
COMMENT=	Curl statistics made simple

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	curl:ftp/curl

USE_GITHUB=	yes
GH_ACCOUNT=	reorx

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
