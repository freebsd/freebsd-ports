# New ports collection makefile for:	py-openbabel
# Date created:		2008-07-18
# Whom:			Max Brazhnikov <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	openbabel
PORTVERSION=	2.2.3
CATEGORIES=	science python
MASTER_SITES=	SF
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Python bindings for openbabel

LIB_DEPENDS=	openbabel.3:${PORTSDIR}/science/openbabel

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
BUILD_WRKSRC=	${WRKSRC}/scripts/python
INSTALL_WRKSRC=	${BUILD_WRKSRC}

PYDISTUTILS_PKGVERSION=	1.5

#Fix build with non-default LOCALBASE
CONFIGURE_ENV+=	OPENBABEL_INSTALL=${LOCALBASE}
MAKE_ENV+=	OPENBABEL_INSTALL=${LOCALBASE}

.include <bsd.port.mk>
