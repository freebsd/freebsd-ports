# Created by: Alexander Leidinger
# $FreeBSD$

PORTNAME=		soappy
PORTVERSION=		0.11.6
PORTREVISION=		1
CATEGORIES=		net python
MASTER_SITES=		SF/pywebsvcs/SOAP.py/${PORTVERSION}
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}
DISTNAME=		SOAPpy-${PORTVERSION}

MAINTAINER=		5u623l20@gmail.com
COMMENT=		SOAP implementation

LICENSE=		BSD3CLAUSE

PORTSCOUT=		skipv:0.12.0	# This is a release candidate and is ports tree py*-soappy-devel
USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

BUILD_DEPENDS+=	${PYTHON_SITELIBDIR}/fpconst.py:${PORTSDIR}/math/py-fpconst
RUN_DEPENDS:=	${BUILD_DEPENDS}

CONFLICTS=	py*-soappy-devel-0.12.*

.include <bsd.port.mk>
