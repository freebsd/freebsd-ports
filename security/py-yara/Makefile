# New ports collection makefile for:    py-yara
# Date created:         Mar 7 2011
# Whom:                 wxs@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	yara
PORTVERSION=	1.4a
CATEGORIES=	security
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	yara-python-${PORTVERSION}

MAINTAINER=	wxs@FreeBSD.org
COMMENT=	Python bindings for yara

LIB_DEPENDS=	yara.0:${PORTSDIR}/security/yara

PROJECTHOST=	yara-project
MAKE_JOBS_SAFE=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_EGGINFO=	yara_python-1.4a-py2.7.egg-info

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/yara.so

.include <bsd.port.mk>
