PORTNAME=	nfs-exporter
DISTVERSION=	0.4.4
PORTREVISION=	10
CATEGORIES=	net-mgmt
MASTER_SITES=	CRATESIO
MASTER_SITE_SUBDIR=	freebsd-${PORTNAME}/${DISTVERSION}
DISTNAME=	freebsd-${PORTNAME}-${DISTVERSIONFULL}
DISTFILES=	${CARGO_DIST_SUBDIR}/${DISTNAME}${CARGO_CRATE_EXT}

MAINTAINER=	asomers@FreeBSD.org
COMMENT=	Prometheus exporter for NFS statistics
WWW=		https://github.com/Axcient/freebsd-nfs-exporter

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

# https://github.com/tikv/rust-prometheus/issues/315
NOT_FOR_ARCHS=	powerpc
NOT_FOR_ARCHS_REASON_powerpc=needs 64-bit atomics

BUILD_DEPENDS=	llvm-config${LLVM_DEFAULT}:devel/llvm${LLVM_DEFAULT}

USES=		cargo
USE_RC_SUBR=	nfs_exporter

SUB_LIST=	USER=nobody

PLIST_FILES=	bin/${PORTNAME} \
		share/man/man8/${PORTNAME}.8.gz

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.8 ${STAGEDIR}${PREFIX}/share/man/man8

.include <bsd.port.mk>
