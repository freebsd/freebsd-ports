# Created by: Alexander Leidinger
# $FreeBSD$

PORTNAME=		soappy
PORTVERSION=		0.11.6
CATEGORIES=		net python
MASTER_SITES=		SF/pywebsvcs/SOAP.py/${PORTVERSION}
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}
DISTNAME=		SOAPpy-${PORTVERSION}

MAINTAINER=		5u623l20@gmail.com
COMMENT=		A SOAP implementation

PORTSCOUT=		skipv:0.12.0	# This is a release candidate and is ports tree py*-soappy-devel
USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	SOAPpy

BUILD_DEPENDS+=	${PYTHON_SITELIBDIR}/fpconst.py:${PORTSDIR}/math/py-fpconst
RUN_DEPENDS+=	${PYXML} \
		${BUILD_DEPENDS}

CONFLICTS=	py*-soappy-devel-0.12.*

NO_STAGE=	yes
.include <bsd.port.mk>
