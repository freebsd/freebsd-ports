PORTNAME=	codebook
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.40
CATEGORIES=	textproc

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Spell checker lsp for code
WWW=		https://github.com/blopker/codebook

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgit2.so:devel/libgit2 \
		libssh2.so:security/libssh2

USES=		cargo ssl
USE_GITHUB=	yes
GH_ACCOUNT=	blopker

CARGO_INSTALL_PATH=	crates/codebook-lsp

PLIST_FILES=	bin/codebook-lsp

.include <bsd.port.mk>
