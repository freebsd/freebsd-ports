# Created by: Nicola Vitale	<nivit@email.it>
# $FreeBSD$

PORTNAME=	enchant
PORTVERSION=	1.6.5
PORTREVISION=	4
CATEGORIES=	textproc devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A spellchecking library for Python based on the Enchant library

LIB_DEPENDS=	enchant.1:${PORTSDIR}/textproc/enchant

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes
USE_WX=	2.8
WX_COMPS=	python:run

LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
