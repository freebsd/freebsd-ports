PORTNAME=	minisign
PORTVERSION=	0.9
CATEGORIES=	security

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple tool to sign files and verify signatures
WWW=		https://github.com/jedisct1/minisign

LICENSE=	ISCL

LIB_DEPENDS=	libsodium.so:security/libsodium

USES=	cmake localbase pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	jedisct1

PLIST_FILES=	bin/minisign share/man/man1/minisign.1.gz

.include <bsd.port.mk>
