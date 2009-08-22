# New ports collection makefile for:	py-enchant
# Date created:		2006-04-03
# Whom:			Nicola Vitale	<nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	enchant
PORTVERSION=	1.5.3
CATEGORIES=	textproc devel python
MASTER_SITES=	SF/py${PORTNAME}/py${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${MASTER_SITE_SUBDIR}-${PORTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A spellchecking library for Python based on the Enchant library

LIB_DEPENDS=	enchant.1:${PORTSDIR}/textproc/enchant

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
USE_WX=	2.8
WX_COMPS=	python:run

PYDISTUTILS_PKGNAME=	pyenchant

MAKE_ENV+=	LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
