# $FreeBSD$

PORTNAME=	openethereum
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.1
PORTREVISION=	1
CATEGORIES=	net-p2p

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Fast and feature-rich multi-network Ethereum client

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=		fails to build
BROKEN_FreeBSD_11=	fails to build

BUILD_DEPENDS=	${LOCALBASE}/bin/llvm-config90:devel/llvm90

USES=		cargo

USE_GITHUB=	yes

PLIST_FILES=	bin/${PORTNAME}

CARGO_FEATURES=	final
CARGO_TEST=	yes

MAKE_ENV+=	LLVM_CONFIG_PATH="${LOCALBASE}/bin/llvm-config90"

.include "${.CURDIR}/Makefile.crates"

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
