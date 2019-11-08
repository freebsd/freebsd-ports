# $FreeBSD$

PORTNAME=	tornova
PORTVERSION=	0.2.3
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	net-mgmt

MAINTAINER=	neel@neelc.org
COMMENT=	Frontend for Tor

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}stem>=0.18:security/py-stem@${PY_FLAVOR} \
		tor:security/tor

USE_GITHUB=	yes
GH_ACCOUNT=	neelchauhan
GH_PROJECT=	TorNova

USES=		gnome python:2.7
USE_PYTHON=	autoplist distutils
USE_GNOME=	gtk30 pygobject3
NO_ARCH=	yes

.include <bsd.port.mk>
