# New ports collection makefile for:	py-soappy
# Date created:		2 Aug 2004
# Whom:	      		Alexander Leidinger
#
# $FreeBSD$
#

PORTNAME=		soappy
PORTVERSION=		0.11.6
CATEGORIES=		net python
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pywebsvcs
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}
DISTNAME=		SOAPpy-${PORTVERSION}

MAINTAINER=		marcus@corp.grupos.com.br
COMMENT=		A SOAP implementation

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes

BUILD_DEPENDS+=	${PYTHON_SITELIBDIR}/fpconst.py:${PORTSDIR}/math/py-fpconst
RUN_DEPENDS+=	${PYXML} \
		${BUILD_DEPENDS}

CONFLICTS=	py*-soappy-devel-0.12.*

.include <bsd.port.mk>
