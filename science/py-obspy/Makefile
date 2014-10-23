# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	obspy
PORTVERSION=	0.9.2
PORTREVISION=	2
CATEGORIES=	science python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Python framework for seismological observatories

LICENSE=	LGPL3

BUILD_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.6.0:${PORTSDIR}/science/py-scipy \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=0.90.1:${PORTSDIR}/math/py-matplotlib \
		${PYTHON_PKGNAMEPREFIX}lxml>=2.2:${PORTSDIR}/devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}suds>=0.4.0:${PORTSDIR}/net/py-suds \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy>=0:${PORTSDIR}/databases/py-sqlalchemy
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=			fortran zip python
USE_LDCONFIG=		yes
LDFLAGS+=		-shared
USE_PYTHON=		distutils autoplist

LDFLAGS+=	-shared

post-patch:
	${REINPLACE_CMD} -e "s#FC#${FC}#g" ${WRKSRC}/setup.py

.include <bsd.port.mk>
