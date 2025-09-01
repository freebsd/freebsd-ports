PORTNAME=	kalker
DISTVERSIONPREFIX=	v
DISTVERSION=	2.2.1
PORTREVISION=	8
CATEGORIES=	math

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Scientific calculator that supports math-like syntax
WWW=		https://kalker.xyz/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpc.so:math/mpc \
		libmpfr.so:math/mpfr

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	PaddiM8
CARGO_CARGOTOML=	${WRKSRC}/cli/Cargo.toml
CARGO_INSTALL_PATH=	./cli
PLIST_FILES=	bin/kalker

post-patch:
	${REINPLACE_CMD} -e 's,%%LOCALBASE%%,${LOCALBASE},g' ${WRKSRC_crate_gmp-mpfr-sys}/build.rs

.include <bsd.port.mk>
