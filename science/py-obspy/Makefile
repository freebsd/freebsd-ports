# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	obspy
PORTVERSION=	0.8.4
CATEGORIES=	science python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
#DISTNAME=	${PORTNAME:S,-,.,}-${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Core Classes of Python for Seismological Observatories

BUILD_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.6.0:${PORTSDIR}/science/py-scipy \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=0.90.1:${PORTSDIR}/math/py-matplotlib \
		${PYTHON_PKGNAMEPREFIX}lxml>=2.2:${PORTSDIR}/devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}suds>=0.4.0:${PORTSDIR}/net/py-suds
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_FORTRAN=		yes
USE_ZIP=		yes
USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install
PYEASYINSTALL_ARCHDEP=	yes

post-patch:
	${REINPLACE_CMD} -e "s#FC#${FC}#g" ${WRKSRC}/setup.py

.include <bsd.port.mk>
