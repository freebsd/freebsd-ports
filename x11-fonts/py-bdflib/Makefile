# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bdflib
PORTVERSION=	1.0.0
CATEGORIES=	x11-fonts python
MASTER_SITES=	CHEESESHOP/source/b/${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Library for working with BDF font files

LICENSE=	GPLv3

USE_PYTHON=	2
USE_PYDISTUTILS=	yes

post-patch:
	@${REINPLACE_CMD} -e '/def/!s,guess_version(),"${PORTVERSION}",' \
		${WRKSRC}/${PYSETUP}

.include <bsd.port.mk>
