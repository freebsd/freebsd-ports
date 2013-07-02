# Created by: Jason Helfman <jgh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	virtinst
PORTVERSION=	0.600.4
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://virt-manager.org/download/sources/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Module to help in starting installations inside of virtual machines

LIB_DEPENDS=	virt.1001:${PORTSDIR}/devel/libvirt
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}urlgrabber>=3.9.1:${PORTSDIR}/www/py-urlgrabber

FETCH_ARGS=	-Fpr
USES=		gettext
USE_PYTHON_RUN=	yes
USE_PYTHON_BUILD=	yes
USE_PYDISTUTILS=	yes

MAN1=		virt-clone.1 virt-convert.1 virt-image.1 virt-install.1
MAN5=		virt-image.5
MANCOMPRESSED=	no

post-patch-script:
	${REINPLACE_CMD} 's|share/man|man|g' \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
