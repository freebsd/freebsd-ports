# New ports collection makefile for:	py-xmlrpc
# Date created:				22 April 2001
# Whom:					Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$
#

PORTNAME=	xmlrpc
PORTVERSION=	0.8.2
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR= ${PKGNAMEPREFIX}${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	perky@python.or.kr

BUILD_DEPENDS=	${PYDISTUTILS}

WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_SUB+=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR:S/^${LOCALBASE}\///g}

USE_PYTHON=	yes
SETUP_CMD=	cd ${WRKSRC} && ${PYTHON_CMD} setup.py

do-build:
	${SETUP_CMD} build

do-install:
	${SETUP_CMD} install

.include <bsd.port.mk>
