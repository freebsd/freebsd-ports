# $FreeBSD$

PORTNAME=	plover
PORTVERSION=	2.2.0
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	http://launchpadlibrarian.net/88624187/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Open source solution for stenography

LICENSE=	GPLv2

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xlib>=0:x11-toolkits/py-xlib \
		${PYTHON_PKGNAMEPREFIX}serial>=0:comms/py-serial \
		${PYTHON_PKGNAMEPREFIX}lockfile>=0:devel/py-lockfile

USES=		python
USE_PYTHON=	distutils
USE_WX=		3.0+
WX_COMPS=	wx
WX_UNICODE=	yes

post-patch:
	@${REINPLACE_CMD} -e "s@%%PREFIX%%@${PREFIX}@g" ${WRKSRC}/setup.py

.include <bsd.port.mk>
