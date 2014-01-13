# Created by: Julien Laffaye <kimelto@gmail.com>
# $FreeBSD$

PORTNAME=	closure-linter
PORTVERSION=	2.3.5
CATEGORIES=	www devel
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	closure_linter-${PORTVERSION}

MAINTAINER=	jlaffaye@FreeBSD.org
COMMENT=	JavaScript linter

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gflags:${PORTSDIR}/devel/py-gflags

USE_PYTHON=	2
USE_PYDISTUTILS=easy_install

PLIST_FILES=	bin/fixjsstyle \
		bin/gjslint \
		%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

NO_STAGE=	yes
.include <bsd.port.mk>
