PORTNAME=	feluda
DISTVERSIONPREFIX=	v
DISTVERSION=	1.9.8 # Cargo.lock patched: `make patch cargo-crates`
PORTREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	nxjoseph@protonmail.com
COMMENT=	Detect license usage restrictions in your project
WWW=		https://github.com/anistark/feluda

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgit2.so:devel/libgit2 \
		libssh2.so:security/libssh2

USES=		cargo localbase ssl
USE_GITHUB=	yes
GH_ACCOUNT=	anistark

# OPENSSL_NO_VENDOR needs openssl-src present so I'm using Cargo.lock and Cargo.toml patches:
# first to not fetch openssl-src tarball and later to remove git2 ossl vendored feature.
CARGO_ENV=	OPENSSL_NO_VENDOR=1

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
