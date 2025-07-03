PORTNAME=	grass
DISTVERSION=	0.13.4
PORTREVISION=	2
CATEGORIES=	textproc

MAINTAINER=	vishwin@FreeBSD.org
COMMENT=	A Sass compiler written purely in Rust
WWW=		https://github.com/${GH_ACCOUNT}/${GH_PROJECT}

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
CARGO_INSTALL_PATH=	crates/lib

USE_GITHUB=	yes
GH_ACCOUNT=	connorskees
GH_TUPLE=	sass:sass-spec:f726527:sass_spec/sass-spec

PLIST_FILES=	bin/grass

.include <bsd.port.mk>
