# Created by: Joe Maloney <jmaloney@ixsystems.com>
# $FreeBSD$

PORTNAME=	ixautomation
PORTVERSION=	18.02.01
CATEGORIES=	sysutils
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jmaloney@ixsystems.com
COMMENT=	Automation framework for iXsystems projects

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pip>0:devel/py-pip@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-capturelog>=0:devel/py-pytest-capturelog@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-runner>=0:devel/py-pytest-runner@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>=0:devel/py-pytest-xdist@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}selenium>=0:www/py-selenium@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cache>=0:devel/py-pytest-cache@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-localserver>=0:devel/py-pytest-localserver@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-tornado>=0:devel/py-pytest-tornado@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ws4py>=0:www/py-ws4py@${FLAVOR} \
		${LOCALBASE}/sbin/vm:sysutils/vm-bhyve \
		${LOCALBASE}/bin/expect:lang/expect \
		${LOCALBASE}/bin/firefox:www/firefox-esr \
		${LOCALBASE}/bin/geckodriver:www/geckodriver \
		xorg-vfbserver>=0:x11-servers/xorg-vfbserver \
		bhyve-firmware>=0:sysutils/bhyve-firmware

WRKSRC_SUBDIR=  src
USES=		python:3.6
USE_PYTHON=	distutils
MAKE_ARGS=	PREFIX=${STAGEDIR}${PREFIX}

USE_GITHUB=	yes
GH_ACCOUNT=	ixsystems
GH_PROJECT=	ixautomation
GH_TAGNAME=	e822778bcc864b12d99a23461711970275f1d883

.include <bsd.port.mk>
