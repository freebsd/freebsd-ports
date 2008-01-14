# New ports collection makefile for:	py-mako
# Date created:		April 23 2007
# Whom:			Dryice Liu <dryice@dryice.name>
#
# $FreeBSD$
#

PORTNAME=	mako
PORTVERSION=	0.1.10
CATEGORIES=	textproc www python
MASTER_SITES=	http://www.makotemplates.org/downloads/ \
		${MASTER_SITE_CHEESESHOP} \
		http://dryice.name/computer/FreeBSD/distfiles/
MASTER_SITE_SUBDIR=	source/M/Mako
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Mako-${PORTVERSION}

MAINTAINER=	dryice@FreeBSD.org
COMMENT=	Super-fast templating language in Python

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beaker>=0.7.3:${PORTSDIR}/www/py-beaker \
		${PYTHON_PKGNAMEPREFIX}Babel>=0.8.1:${PORTSDIR}/devel/py-babel
RUN_DEPENDS+=	${BUILD_DEPENDS}

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	Mako

.include <bsd.port.mk>
