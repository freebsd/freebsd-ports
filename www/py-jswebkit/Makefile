# Created by: Ju Pengfei <jupengfei@gmail.com>
# $FreeBSD$

PORTNAME=	jswebkit
PORTVERSION=	0.0.3
PORTREVISION=	5
CATEGORIES=	www python
MASTER_SITES=	http://archive.ubuntu.com/ubuntu/pool/universe/p/python-jswebkit/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	WebKit/JavaScriptCore Python bindings

LIB_DEPENDS=	libwebkitgtk-1.0.so:www/webkit-gtk2

USES=		pkgconfig python:2.7
USE_PYTHON=	distutils autoplist cython cython_run
WRKSRC=		${WRKDIR}/python-${PORTNAME}-${PORTVERSION}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/jswebkit.so

.include <bsd.port.mk>
