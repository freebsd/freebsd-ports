# Created by: Ju Pengfei <jupengfei@gmail.com>
# $FreeBSD$

PORTNAME=		jswebkit
PORTVERSION=		0.0.3
PORTREVISION=	2
CATEGORIES=		www python
MASTER_SITES=		GOOGLE_CODE
PROJECTHOST=		gwrite
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}
DISTNAME=		python-${PORTNAME}-${PORTVERSION}

MAINTAINER=		ports@FreeBSD.org
COMMENT=		WebKit/JavaScriptCore Python bindings

BUILD_DEPENDS=		cython:${PORTSDIR}/lang/cython
LIB_DEPENDS=		webkitgtk-1.0:${PORTSDIR}/www/webkit-gtk2
RUN_DEPENDS:=		${BUILD_DEPENDS}

PLIST_FILES=		%%PYTHON_SITELIBDIR%%/jswebkit.so

USES=			pkgconfig
USE_PYTHON=		-2.7
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	python_jswebkit

NO_STAGE=	yes
.include <bsd.port.mk>
