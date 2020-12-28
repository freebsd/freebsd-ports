# Created by: Bartek Rutkowski robak@FreeBSD.org
# $FreeBSD$

PORTNAME=	pyvmomi
DISTVERSION=	6.5
PORTREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP/source/p/${PORTNAME}

MAINTAINER=	robak@FreeBSD.org
COMMENT=	Python SDK for the VMware vSphere API of ESX, ESXi, and vCenter

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=2.3.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.5.2:devel/py-six@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils concurrent optsuffix

post-patch:
	${REINPLACE_CMD} -E "/data_files/s|\[\(''|\[\('${DOCSDIR}'|"  ${WRKSRC}/setup.py

.include <bsd.port.mk>
