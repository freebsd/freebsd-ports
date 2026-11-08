PORTNAME=	faro
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.7
CATEGORIES=	net-im

MAINTAINER=	dch@skunkwerks.at
COMMENT=	Terminal client for Signal, built for people who live in tmux
WWW=		https://getfaro.dev

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	protoc:devel/protobuf

USES=		cargo ssl

USE_GITHUB=	yes
GH_ACCOUNT=	harababurel

GH_TUPLE=	whisperfish:presage:6f630791b2c7bf3d5b00c75f5a6c94131bf79c8c:whisperfish_presage \
		harababurel:libsignal-service-rs:7a8c7fa4f3b3c88d0ea385fc88033d2742a99d8d:harababurel_libsignal_service \
		whisperfish:rusqlite:2a42b3354c9194700d08aa070f70a131a470e7dc:whisperfish_rusqlite \
		signalapp:libsignal:v0.99.0:signalapp_libsignal \
		signalapp:SparsePostQuantumRatchet:v1.5.3:signalapp_spqr

CARGO_INSTALL_PATH=	crates/faro

post-patch:
	@${REINPLACE_CMD} -e 's|https://github.com/whisperfish/libsignal-service-rs", rev = "fae0679db1659bb2decb650fd07437c5dfd72f37|https://github.com/harababurel/libsignal-service-rs", rev = "7a8c7fa4f3b3c88d0ea385fc88033d2742a99d8d|' \
		${WRKSRC_crate_presage}/presage/Cargo.toml

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md \
		${WRKSRC}/THIRD_PARTY_NOTICES.md ${STAGEDIR}${DOCSDIR}

PLIST_FILES=	bin/faro
PORTDOCS=	README.md THIRD_PARTY_NOTICES.md

OPTIONS_DEFINE=		DOCS
OPTIONS_DEFAULT=	DOCS

.include <bsd.port.mk>
