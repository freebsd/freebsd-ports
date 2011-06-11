# New ports collection makefile for:	py-beanstalkc
# Date created:		2011-03-18
# Whom:			Li-Wen Hsu <lwhsu@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	beanstalkc
PORTVERSION=	0.2.0
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	eyecue+freebsdports@gmail.com
COMMENT=	A simple beanstalkd client library

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

OPTIONS=	PYYAML	"YAML support"	on

# bypass infrastructure bug
OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/${PYEASYINSTALL_EGG}

.include <bsd.port.options.mk>

.if defined(WITH_PYYAML)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}yaml>0:${PORTSDIR}/devel/py-yaml
.endif

.include <bsd.port.mk>
