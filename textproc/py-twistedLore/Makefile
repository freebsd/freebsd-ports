# Created by: Neal Nelson <neal@nelson.name>
# $FreeBSD$

PORTNAME=	twistedLore
PORTVERSION=	14.0.0
CATEGORIES=	textproc python
MASTER_SITES=	http://twistedmatrix.com/Releases/Lore/${PORTVERSION:R}/ \
		LOCAL/sunpoet
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	TwistedLore-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Documentation generator with HTML and LaTeX support

LICENSE=	MIT

USE_PYTHON=	2
USE_PYDISTUTILS=yes
PYDISTUTILS_AUTOPLIST=	yes
USES=		tar:bzip2 twisted

.include <bsd.port.mk>
