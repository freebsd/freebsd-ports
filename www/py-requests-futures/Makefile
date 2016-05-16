# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	requests-futures
PORTVERSION=	0.9.7
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	feld@FreeBSD.org
COMMENT=	HTTP library written in Python for human beings

LICENSE=	APACHE20

USES=		python
USE_PYTHON=	autoplist distutils

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_VER} == "2.7"
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}futures>0:devel/py-futures
.endif

.include <bsd.port.post.mk>
