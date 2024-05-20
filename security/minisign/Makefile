PORTNAME=	minisign
PORTVERSION=	0.11
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	https://github.com/jedisct1/minisign/releases/download/${PORTVERSION}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple tool to sign files and verify digital signatures
WWW=		https://jedisct1.github.io/minisign/ \
		https://github.com/jedisct1/minisign

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libsodium.so:security/libsodium

USES=		cmake localbase pkgconfig

CMAKE_OFF=	BUILD_STATIC_EXECUTABLES STATIC_LIBSODIUM
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/minisign \
		share/man/man1/minisign.1.gz

.include <bsd.port.mk>
