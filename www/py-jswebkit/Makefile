# New ports collection makefile for:	py-jswebkit
# Date created:				07 Mar 2010
# Whom:					Ju Pengfei <jupengfei@gmail.com>
#
# $FreeBSD$
#

PORTNAME=		jswebkit
PORTVERSION=		0.0.3
CATEGORIES=		www python
MASTER_SITES=		GOOGLE_CODE
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}
DISTNAME=		python-${PORTNAME}-${PORTVERSION}

MAINTAINER=		jupengfei@gmail.com
COMMENT=		WebKit/JavaScriptCore Python bindings

BUILD_DEPENDS=		cython:${PORTSDIR}/lang/cython
LIB_DEPENDS=		webkit:${PORTSDIR}/www/webkit-gtk2
RUN_DEPENDS=		${BUILD_DEPENDS}

PLIST_FILES=		%%PYTHON_SITELIBDIR%%/jswebkit.so

PROJECTHOST=		gwrite

WRKSRC=			${WRKDIR}/python-jswebkit
USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	python_jswebkit
PYDISTUTILS_PKGVERSION=	0.0.2

.include <bsd.port.mk>
