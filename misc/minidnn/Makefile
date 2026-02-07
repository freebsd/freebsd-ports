PORTNAME=	minidnn
DISTVERSION=	g20200330
PORTREVISION=	1
CATEGORIES=	misc # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Header-only C++ library for deep neural networks
WWW=		https://github.com/yixuan/MiniDNN

LICENSE=	MPL20

USES=		eigen:3,run
USE_GITHUB=	yes
GH_ACCOUNT=	yixuan
GH_PROJECT=	MiniDNN
GH_TAGNAME=	525ff216a6b5f576d4d679aee6a4636994bd4f23

NO_BUILD=	yes
NO_ARCH=	yes

do-install:
	@cd ${WRKSRC}/include && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/${PORTNAME}

.include <bsd.port.mk>
