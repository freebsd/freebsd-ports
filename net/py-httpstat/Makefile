# Created by: Danilo G. Baio <dbaio@FreeBSD.org>
# $FreeBSD$

PORTNAME=	httpstat
PORTVERSION=	1.2.1
CATEGORIES=	net python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Curl statistics made simple

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	curl:ftp/curl

USES=		python

USE_GITHUB=	yes
GH_ACCOUNT=	reorx

USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

.include <bsd.port.mk>
