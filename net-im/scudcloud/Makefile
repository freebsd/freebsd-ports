# Created by: Nicola Stanislao Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	scudcloud
PORTVERSION=	1.65
DISTVERSIONPREFIX=	v
PORTREVISION=	3
CATEGORIES=	net-im

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Desktop client app for Slack

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jsmin>0:devel/py-jsmin@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>0:devel/py-dbus@${PY_FLAVOR}

GH_ACCOUNT=	raelgc

HUNSPELL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hunspell>0:textproc/py-hunspell@${PY_FLAVOR} \
			falkon:www/falkon

INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	HUNSPELL

USES=		gnome python:3.5+ pyqt:5
USE_PYQT=	sip_run webkit_run webkitwidgets_run
USE_GITHUB=	yes
USE_PYTHON=	autoplist distutils optsuffix
NO_ARCH=	yes

post-patch:
		@${REINPLACE_CMD} -i.bak -e 's,%%LOCALBASE%%,${LOCALBASE},1' \
			${WRKSRC}/share/${PORTNAME}.desktop \
			${WRKSRC}/${PORTNAME}/resources.py

.include <bsd.port.mk>
