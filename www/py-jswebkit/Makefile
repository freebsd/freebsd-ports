# Created by: Ju Pengfei <jupengfei@gmail.com>
# $FreeBSD$

PORTNAME=	jswebkit
PORTVERSION=	0.0.3
PORTREVISION=	4
CATEGORIES=	www python
MASTER_SITES=	GOOGLE_CODE
PROJECTHOST=	gwrite
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	WebKit/JavaScriptCore Python bindings

BUILD_DEPENDS=	cython:lang/cython
RUN_DEPENDS:=	${BUILD_DEPENDS}
LIB_DEPENDS=	libwebkitgtk-1.0.so:www/webkit-gtk2

USES=		pkgconfig python:2
USE_PYTHON=	distutils autoplist

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/jswebkit.so

.include <bsd.port.mk>
