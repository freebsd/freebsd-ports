# New ports collection makefile for:	py-clientform
# Date created:				25 Jun 2004
# Whom:					"Choe, Cheng-Dae" <whitekid@netian.com>
#
# $FreeBSD$
#

PORTNAME=	clientform
PORTVERSION=	0.2.10
CATEGORIES=	www python
MASTER_SITES=	http://wwwsearch.sourceforge.net/ClientForm/src/ \
		CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	ClientForm-${PORTVERSION}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Client-side HTTP Form for Python

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	ClientForm

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

.include <bsd.port.mk>
