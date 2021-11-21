# Created by: Bartek Rutkowski robak@FreeBSD.org

PORTNAME=	pyvmomi
DISTVERSION=	7.0.3
CATEGORIES=	net python

MAINTAINER=	robak@FreeBSD.org
COMMENT=	Python SDK for the VMware vSphere API of ESX, ESXi, and vCenter

USE_GITHUB=     yes
GH_ACCOUNT=     vmware
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	v${PORTVERSION}

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=2.3.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.7.3:devel/py-six@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils concurrent optsuffix

post-patch:
	${REINPLACE_CMD} -E "/data_files/s|\[\(''|\[\('${DOCSDIR}'|"  ${WRKSRC}/setup.py

.include <bsd.port.mk>
