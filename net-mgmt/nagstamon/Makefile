# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nagstamon
PORTVERSION=	3.4.1
PORTREVISION=	4
CATEGORIES=	net-mgmt python
MASTER_SITES=	https://nagstamon.ifw-dresden.de/files/stable/ \
		LOCAL/ehaupt
DISTNAME=	Nagstamon-${PORTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Nagios status monitor for your desktop

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}keyring>0:security/py-keyring@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=2.0:sysutils/py-psutil@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4.2.1:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}keyring>0:security/py-keyring@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-kerberos>0:security/py-requests-kerberos@${PY_FLAVOR}

USES=		cpe python:3.6+ pyqt:5
USE_PYTHON=	autoplist distutils noflavors
USE_PYQT=	core_run dbus_run gui_run multimedia_run network_run sip_run \
		svg_run widgets_run

CPE_VENDOR=	henri_wahl
NO_ARCH=	yes

WRKSRC=		${WRKDIR}/Nagstamon

.include <bsd.port.mk>
