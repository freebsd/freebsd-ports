# $FreeBSD$

PORTNAME=	plover
PORTVERSION=	2.2.0
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://launchpadlibrarian.net/88624187/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Open source solution for stenography

LICENSE=	GPLv2

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xlib>=0:${PORTSDIR}/x11-toolkits/py-xlib \
		${PYTHON_PKGNAMEPREFIX}serial>=0:${PORTSDIR}/comms/py-serial \
		${PYTHON_PKGNAMEPREFIX}lockfile>=0:${PORTSDIR}/devel/py-lockfile

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
USE_WX=		2.8
WX_COMPS=	wx
WX_UNICODE=	yes

post-patch:
	@${REINPLACE_CMD} -e "s@%%PREFIX%%@${PREFIX}@g" ${WRKSRC}/setup.py

.include <bsd.port.mk>
