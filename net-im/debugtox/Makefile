PORTNAME=	debugtox
DISTVERSION=	g20250207
CATEGORIES=	net-im net-p2p

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Very simple Tox client to help debug and play with the API
WWW=		https://tox.chat \
		https://github.com/TokTok/debugtox

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN=		fails to compile with toxcore-0.2.20

LIB_DEPENDS=	libsodium.so:security/libsodium \
		libtoxcore.so:net-im/tox

USES=		cmake compiler:c++17-lang gl pkgconfig qt:6
USE_QT=		base
USE_GL=		opengl

USE_GITHUB=	yes
GH_ACCOUNT=	TokTok
GH_TAGNAME=	725f7b9

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
