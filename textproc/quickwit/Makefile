PORTNAME=	quickwit
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.2
PORTREVISION=	10
CATEGORIES=	textproc

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Sub-second search & analytics engine on cloud storage
WWW=		https://quickwit.io/

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE_AGPLv3.0.txt

BUILD_DEPENDS=	${LOCALBASE}/bin/protoc:devel/protobuf
LIB_DEPENDS=	libzstd.so:archivers/zstd

BROKEN_i386=	fails to build
USES=			cargo pkgconfig
USE_GITHUB=		yes
GH_ACCOUNT=		quickwit-oss
#GH_TUPLE=		quickwit-oss:rust-sasl:daca921:rust_sasl/cargo-crates/sasl2-sys
CARGO_CARGOLOCK=	${WRKSRC}/${PORTNAME}/Cargo.lock
CARGO_CARGOTOML=	${WRKSRC}/${PORTNAME}/Cargo.toml
CARGO_INSTALL_PATH=	${PORTNAME}/quickwit-cli

OPTIONS_DEFINE=		DOCS
OPTIONS_DEFAULT=	DOCS

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA}	${WRKSRC}/config/quickwit.yaml ${STAGEDIR}${ETCDIR}/quickwit.yaml.sample
	${RM} -v ${STAGEDIR}${PREFIX}/bin/generate_markdown

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
