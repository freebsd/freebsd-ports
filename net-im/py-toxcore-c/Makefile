# Created by: Yuri Victorovich
# $FreeBSD$

PORTNAME=	toxcore-c
DISTVERSION=	0.180219
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

USES=		localbase python
USE_GITHUB=	yes
GH_ACCOUNT=	TokTok
GH_PROJECT=	py-toxcore-c
GH_TAGNAME=	2c1b9d6
USE_PYTHON=	distutils autoplist

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/pytox.so

.include <bsd.port.mk>
