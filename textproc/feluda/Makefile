PORTNAME=	feluda
DISTVERSIONPREFIX=	v
DISTVERSION=	1.13.0 # Cargo.lock patched: `make patch cargo-crates`
CATEGORIES=	textproc devel

MAINTAINER=	nxjoseph@FreeBSD.org
COMMENT=	Detect license usage restrictions in a project
WWW=		https://github.com/anistark/feluda

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgit2.so:devel/libgit2 \
		libssh2.so:security/libssh2
RUN_DEPENDS=	noto-emoji>0:x11-fonts/noto-emoji

USES=		cargo localbase ssl
USE_GITHUB=	yes
GH_ACCOUNT=	anistark

# OPENSSL_NO_VENDOR needs openssl-src present so I'm using Cargo.lock and Cargo.toml patches:
# first to not fetch openssl-src tarball and later to remove git2 ossl vendored feature.
CARGO_ENV=	OPENSSL_NO_VENDOR=1

PLIST_FILES=	bin/feluda

.include <bsd.port.mk>
