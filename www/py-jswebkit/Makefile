# New ports collection makefile for:	py-jswebkit
# Date created:				07 Mar 2010
# Whom:					Ju Pengfei <jupengfei@gmail.com>
#
# $FreeBSD$
#

PORTNAME=		jswebkit
PORTVERSION=		0.0.1
CATEGORIES=		www python
MASTER_SITES=		GOOGLE_CODE
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}
DISTNAME=		python-${PORTNAME}-${PORTVERSION}

MAINTAINER=		jupengfei@gmail.com
COMMENT=		WebKit/JavaScriptCore Python bindings

BUILD_DEPENDS=		cython:${PORTSDIR}/lang/cython
LIB_DEPENDS=		webkit:${PORTSDIR}/www/webkit-gtk2
RUN_DEPENDS=		${BUILD_DEPENDS}

PROJECTHOST=		gwrite

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_NOEGGINFO=	yes

.include <bsd.port.mk>
