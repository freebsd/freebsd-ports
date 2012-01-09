# New ports collection makefile for:	closure-linter
# Date created:		2011-01-10
# Whom:			Julien Laffaye <kimelto@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	closure-linter
PORTVERSION=	2.3.1
PORTREVISION=	1
CATEGORIES=	www devel
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	closure_linter-${PORTVERSION}

MAINTAINER=	jlaffaye@FreeBSD.org
COMMENT=	JavaScript linter

LICENSE=	AL2

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/gflags:${PORTSDIR}/devel/py-gflags
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gflags:${PORTSDIR}/devel/py-gflags

USE_PYTHON=	-2.7
USE_PYDISTUTILS=easy_install

PLIST_FILES=	bin/fixjsstyle \
		bin/gjslint \
		%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

.include <bsd.port.mk>
