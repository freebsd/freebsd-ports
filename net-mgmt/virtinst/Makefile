# Created by: Jason Helfman <jgh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	virtinst
PORTVERSION=	0.600.4
PORTREVISION=	4
CATEGORIES=	net-mgmt
MASTER_SITES=	http://virt-manager.org/download/sources/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Module to help in starting installations inside of virtual machines

LIB_DEPENDS=	libvirt.so:${PORTSDIR}/devel/libvirt
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}urlgrabber>=3.9.1:${PORTSDIR}/www/py-urlgrabber

USES=		gettext python
USE_PYTHON=	distutils

post-patch:
	${REINPLACE_CMD} 's|share/man|man|g' \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
