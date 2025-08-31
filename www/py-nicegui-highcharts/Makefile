PORTNAME=	nicegui-highcharts
DISTVERSION=	2.1.0
PORTREVISION=	1
CATEGORIES=	www graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	nicegui_highcharts-${PORTVERSION}

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	NiceGUI extension providing highcharts elements
WWW=		https://github.com/zauberzeug/nicegui-highcharts

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>0:devel/py-poetry-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

OPTIONS_DEFAULT=	NICEGUI_GUI
OPTIONS_SINGLE=		NICEGUI
OPTIONS_SINGLE_NICEGUI=	NICEGUI_GUI NICEGUI_NOGUI

NICEGUI_GUI_DESC=	Use www/py-nicegui
NICEGUI_NOGUI_DESC=	Use www/py-nicegui-nogui

NICEGUI_GUI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nicegui>=0:www/py-nicegui@${PY_FLAVOR}
NICEGUI_NOGUI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nicegui-nogui>=0:www/py-nicegui-nogui@${PY_FLAVOR}

.include <bsd.port.mk>
