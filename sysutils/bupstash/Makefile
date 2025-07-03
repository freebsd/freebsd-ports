PORTNAME=	bupstash
DISTVERSIONPREFIX=	v
DISTVERSION=	0.12.0
PORTREVISION=	25
CATEGORIES=	sysutils

MAINTAINER=	felix@userspace.com.au
COMMENT=	Easy and efficient encrypted backups
WWW=		https://bupstash.io

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libsodium.so:security/libsodium

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	andrewchambers

CARGO_FEATURES=	--no-default-features

PLIST_FILES=	bin/bupstash

.include <bsd.port.mk>
