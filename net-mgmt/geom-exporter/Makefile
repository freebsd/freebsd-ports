PORTNAME=	geom-exporter
DISTVERSION=	0.1.1
PORTREVISION=	10
CATEGORIES=	net-mgmt
MASTER_SITES=	CRATESIO
MASTER_SITE_SUBDIR=	freebsd-${PORTNAME}/${DISTVERSION}
DISTNAME=	freebsd-${PORTNAME}-${DISTVERSIONFULL}
DISTFILES=	${CARGO_DIST_SUBDIR}/${DISTNAME}${CARGO_CRATE_EXT}

MAINTAINER=	asomers@FreeBSD.org
COMMENT=	Prometheus exporter for GEOM statistics
WWW=		https://github.com/asomers/gstat-rs

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

# https://github.com/tikv/rust-prometheus/issues/315
NOT_FOR_ARCHS=	powerpc
NOT_FOR_ARCHS_REASON_powerpc=needs 64-bit atomics

BUILD_DEPENDS=	llvm-config${LLVM_DEFAULT}:devel/llvm${LLVM_DEFAULT}

USES=		cargo
USE_RC_SUBR=	geom_exporter

SUB_LIST=	USER=nobody

PLIST_FILES=	bin/${PORTNAME} \
		share/man/man8/${PORTNAME}.8.gz

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.8 ${STAGEDIR}${PREFIX}/share/man/man8

.include <bsd.port.mk>
