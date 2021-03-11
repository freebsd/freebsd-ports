# $FreeBSD$

PORTNAME=	nbxmpp
DISTVERSION=	2.0.2
CATEGORIES=	net-im devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Non-blocking Jabber/XMPP module

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}precis_i18n>=1.0.0:textproc/py-precis_i18n@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}idna>=0:dns/py-idna@${PY_FLAVOR}

USES=		gnome python:3.7+
USE_GNOME=	pygobject3
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

.include <bsd.port.mk>
