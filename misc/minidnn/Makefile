# $FreeBSD$

PORTNAME=	minidnn
DISTVERSION=	g20191209
CATEGORIES=	misc # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Header-only C++ library for deep neural networks

LICENSE=	MPL20

USES=		eigen:3,run
USE_GITHUB=	yes
GH_ACCOUNT=	yixuan
GH_PROJECT=	MiniDNN
GH_TAGNAME=	57f1653c28859c689e5d8706b35d591a00e37a56

NO_BUILD=	yes
NO_ARCH=	yes

do-install:
	@cd ${WRKSRC}/include && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/${PORTNAME}

.include <bsd.port.mk>
