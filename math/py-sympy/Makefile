# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	sympy
PORTVERSION=	0.7.6.1
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Python Library For Symbolic Mathematics

LICENSE=	BSD3CLAUSE

USES=		python
USE_PYTHON=	autoplist distutils

OPTIONS_DEFINE=	PYGLET
PYGLET_DESC=	Enable plotting support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYGLET}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pyglet>=1.1.2:${PORTSDIR}/graphics/py-pyglet
.endif

post-patch:
	@${REINPLACE_CMD} -e "s#share/man/man1#man/man1#" ${WRKSRC}/setup.py

.include <bsd.port.mk>
