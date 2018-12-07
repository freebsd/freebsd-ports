# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xmpppy
PORTVERSION=	0.5.0
PORTREVISION=	2
CATEGORIES=	net-im python
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}-rc1/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION}rc1

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python library that provides easy scripting with Jabber

LICENSE=	GPLv2+

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dnspython>=1.7.1:dns/py-dnspython@${PY_FLAVOR}

USES=		python:2.7 shebangfix
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

PORTSCOUT=	ignore:1

SHEBANG_FILES=	doc/examples/*.py

.include <bsd.port.mk>
