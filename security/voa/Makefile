PORTNAME=	voa
DISTVERSION=	0.7.0
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	CRATESIO
# XXX Teach USES=cargo to have proper default
DISTFILES=	${CARGO_DIST_SUBDIR}/${DISTNAME}${CARGO_CRATE_EXT}

MAINTAINER=	vishwin@FreeBSD.org
COMMENT=	Verification of OS Artifacts (VOA) command-line interface
WWW=		https://voa.archlinux.page/

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual

USES=	cargo

CARGO_FEATURES=	cli

PLIST_FILES=	bin/voa

.include <bsd.port.mk>
