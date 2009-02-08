# ex:ts=8
# Ports collection makefile for:	py-mechanize
# Date created:			Apr 29, 2005
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	mechanize
PORTVERSION=	0.1.11
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP \
		http://wwwsearch.sourceforge.net/mechanize/src/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Stateful programmatic web browsing in Python

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}clientform>0:${PORTSDIR}/www/py-clientform
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}clientform>0:${PORTSDIR}/www/py-clientform

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

.include <bsd.port.mk>
