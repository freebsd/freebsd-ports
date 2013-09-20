# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ezjailremote
PORTVERSION=	0.2.2
CATEGORIES=	sysutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Remote control and convenience wrapper for ezjail

RUN_DEPENDS=	ezjail-admin:${PORTSDIR}/sysutils/ezjail \
		${PYTHON_PKGNAMEPREFIX}fabric>0:${PORTSDIR}/devel/py-fabric

USE_GITHUB=	yes
GH_ACCOUNT=	tomster
GH_PROJECT=	ezjail-remote
GH_COMMIT=	9ee5f8b

USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install

NO_STAGE=	yes
.include <bsd.port.mk>
