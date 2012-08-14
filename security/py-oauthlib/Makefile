# New ports collection makefile for:	py-oauthlib
# Date created:				2012-05-23
# Whom:					koobs <koobs.freebsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	oauthlib
PORTVERSION=	0.3.0
CATEGORIES=	security net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs.freebsd@gmail.com
COMMENT=	An RFC-compliant Python implementation of OAuth

LICENSE=	BSD

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycrypto>0:${PORTSDIR}/security/py-pycrypto
RUN_DEPENDS:=	${BUILD_DEPENDS}

# Python3 ready
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

.include <bsd.port.mk>
