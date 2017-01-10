# Created by: Julien Laffaye <kimelto@gmail.com>
# $FreeBSD$

PORTNAME=	closure-linter
PORTVERSION=	2.3.13
PORTREVISION=	2
CATEGORIES=	www devel
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	closure_linter-${PORTVERSION}

MAINTAINER=	jlaffaye@FreeBSD.org
COMMENT=	JavaScript linter

LICENSE=	APACHE20

BROKEN=		Unfetchable (google code has gone away)

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-gflags>=0:devel/py-python-gflags

USES=		python:2
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
