# Created by: Nicola Vitale	<nivit@email.it>
# $FreeBSD$

PORTNAME=	enchant
PORTVERSION=	1.6.5
PORTREVISION=	2
CATEGORIES=	textproc devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A spellchecking library for Python based on the Enchant library

LIB_DEPENDS=	enchant.1:${PORTSDIR}/textproc/enchant

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
USE_WX=	2.8
WX_COMPS=	python:run

PYDISTUTILS_PKGNAME=	pyenchant

LDFLAGS+=	-L${LOCALBASE}/lib

NO_STAGE=	yes
.include <bsd.port.mk>
