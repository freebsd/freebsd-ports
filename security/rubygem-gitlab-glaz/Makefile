PORTNAME=	gitlab-glaz
PORTVERSION=	0.0.3
CATEGORIES=	security rubygems
MASTER_SITES=	RG
DISTFILES:=	${DISTNAME}.gem

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Wraps the Rust-backed GitLab Authorization Service (GLAZ)
WWW=		https://gitlab.com/gitlab-org/ruby/gems/gitlab-glaz

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	protoc:devel/protobuf
RUN_DEPENDS=	rubygem-google-protobuf>=4.35<5:devel/rubygem-google-protobuf \
		rubygem-rb_sys>=0.9.128<0.10:lang/rubygem-rb_sys

USES=		cargo gem gmake llvm:build

GEM_ENV+=	MAKE=gmake \
		${CARGO_ENV}
GEMFILES:=	${DISTNAME}.gem
GEMS_SKIP_SUBDIR=	1
CARGO_CARGOTOML=	${WRKSRC}/ext/glaz/Cargo.toml
CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_ENV+=	CARGO_NET_OFFLINE=true ${MAKE_ENV}
CARGO_VENDOR_DIR=	${WRKSRC}/ext/glaz/cargo-crates

MAKE_ENV+=	PROTOC=${LOCALBASE}/bin/protoc

# update the crates file with:
# make makesum
# make clean extract
# make cargo-crates > Makefile.crates
# make makesum

# Requested upstream: https://gitlab.com/gitlab-org/auth/glaz/-/merge_requests/39
post-patch:
	${CP} ${FILESDIR}/manualpatch-crates_glaz-proto_build.rs ${WRKDIR}/glaz-e1100ed8d93b3db58627229b7c4e16e29905a3d0/crates/glaz-proto/build.rs

.include <bsd.port.mk>
