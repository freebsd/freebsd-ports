PORTNAME=	openethereum
DISTVERSIONPREFIX=	v
DISTVERSION=	3.2.5
PORTREVISION=	1
CATEGORIES=	net-p2p

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Fast and feature-rich multi-network Ethereum client

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo

USE_GITHUB=	yes

PLIST_FILES=	bin/${PORTNAME}

CARGO_FEATURES=	final
CARGO_TEST=	yes

RUSTFLAGS+=	-C link-arg=-fuse-ld=lld

.include "${.CURDIR}/Makefile.crates"

CARGO_GIT_SUBDIR=	rethutil:reth-util:crates/util

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
