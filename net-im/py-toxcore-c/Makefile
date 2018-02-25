# Created by: Yuri Victorovich
# $FreeBSD$

PORTNAME=	toxcore-c
PORTVERSION=	0.170206
PORTREVISION=	2
CATEGORIES=	net-im net-p2p python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python binding for Project-Tox

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libtoxcore.so:net-im/tox \
		libsodium.so:security/libsodium \
		libvpx.so:multimedia/libvpx \
		libopus.so:audio/opus

USE_GITHUB=	yes
GH_ACCOUNT=	TokTok
GH_PROJECT=	py-toxcore-c
GH_TAGNAME=	ebced1f

USES=		python
USE_PYTHON=	distutils autoplist

CFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.mk>
