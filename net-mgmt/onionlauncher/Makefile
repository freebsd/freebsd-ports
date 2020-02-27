# $FreeBSD$

PORTNAME=	onionlauncher
PORTVERSION=	0.0.2
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	net-mgmt

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Launcher for Tor

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Use EOL'd Python 2.7
EXPIRATION_DATE=2020-03-31

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}stem>=0.18:security/py-stem@${PY_FLAVOR} \
		tor:security/tor

USE_GITHUB=	yes
GH_ACCOUNT=	neelchauhan
GH_PROJECT=	OnionLauncher

USES=		pyqt:5 python:2.7
USE_PYTHON=	autoplist distutils
USE_PYQT=	core_run gui_run widgets_run

NO_ARCH=	yes

.include <bsd.port.mk>
