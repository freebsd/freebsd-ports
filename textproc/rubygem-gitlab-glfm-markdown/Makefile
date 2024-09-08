PORTNAME=	gitlab-glfm-markdown
PORTVERSION=	0.0.17
PORTREVISION=	1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Markdown processing for GitLab Flavored Markdown
WWW=		https://gitlab.com/gitlab-org/ruby/gems/gitlab-glfm-markdown

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-rb_sys>=0.9.94<0.9.95:lang/rubygem-rb_sys

USES=		cargo gem gmake llvm:build

# Required to be able to build the rust library the gem uses
GEMFILES:=	${DISTNAME}.gem
DISTFILES+=	${DISTNAME}.gem
GEMS_SKIP_SUBDIR=	1
CARGO_VENDOR_DIR=	${WRKSRC}/ext/glfm_markdown/cargo-crates
CARGO_CARGOTOML=	${WRKSRC}/ext/glfm_markdown/Cargo.toml
CARGO_BUILD=	no
CARGO_INSTALL=	no
GEM_ENV+=	MAKE=gmake

# update the crates file with: make cargo-crates > Makefile.crates

.include <bsd.port.mk>
