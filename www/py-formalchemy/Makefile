# New ports collection makefile for:	py-formalchemy
# Date created:		13 April 2010
# Whom:			ghostonthewire <ghostonthewire at gmail dot com>
#
# $FreeBSD$
#

PORTNAME=	formalchemy
PORTVERSION=	1.3.3
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	FormAlchemy-${DISTVERSION}

MAINTAINER=	ghostonthewire@gmail.com
COMMENT=	Toolkit for creating HTML form elements manually or from SQLAlchemy mapped classes

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlalchemy>=0.4.5:${PORTSDIR}/databases/py-sqlalchemy \
		${PYTHON_PKGNAMEPREFIX}Tempita>=0.4:${PORTSDIR}/textproc/py-Tempita/ \
		${PYTHON_PKGNAMEPREFIX}webhelpers>=0.6.4:${PORTSDIR}/www/py-webhelpers/
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	FormAlchemy
PYDISTUTILS_NOEGGINFO=	yes

.include <bsd.port.mk>
