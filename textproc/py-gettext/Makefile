# $FreeBSD$

PORTNAME=	gettext
PORTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}-${PORTVERSION}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Python Gettext po to mo file compiler

LICENSE=	BSD

USES=		python zip
USE_PYTHON=	distutils autoplist

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} <= 3000
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}unittest2>=0:${PORTSDIR}/devel/py-unittest2
.endif

.include <bsd.port.post.mk>
