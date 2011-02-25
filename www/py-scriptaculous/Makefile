# New ports collection makefile for:	py-scriptaculous
# Date created:		2007-02-14
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	scriptaculous
PORTVERSION=	1.8.1.1
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	http://static.ossdl.de/tgwidgets/downloads/ \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Scriptaculous-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Scriptaculous packaged as TurboGears widgets

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}TurboGears>=1.0.1:${PORTSDIR}/www/py-turbogears
RUN_DEPENDS=	${BUILD_DEPENDS}

PYDISTUTILS_PKGNAME=	Scriptaculous

# Use the same version of www/py-turbogears
USE_PYTHON=	2.5+
USE_PYDISTUTILS=	easy_install
USE_ZIP=	yes

.include <bsd.port.mk>
