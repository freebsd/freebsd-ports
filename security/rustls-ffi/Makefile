PORTNAME=	rustls-ffi
DISTVERSIONPREFIX=	v
DISTVERSION=	0.13.0
PORTREVISION=	1
CATEGORIES=	security

MAINTAINER=	brnrd@FreeBSD.org
COMMENT=	FFI bindings for the rustls TLS library
WWW=		https://github.com/rustls/rustls-ffi

LICENSE=	APACHE20 ISCL MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_ISCL=	${WRKSRC}/LICENSE-ISC
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

BUILD_DEPENDS=	cargo-cbuild:devel/cargo-c

USES=		cargo
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	rustls

do-build:
	@${CARGO_CARGO_RUN} cbuild --verbose --verbose ${CARGO_BUILD_ARGS}

do-install:
	@${CARGO_CARGO_RUN} cinstall --verbose --verbose \
	    --destdir "${STAGEDIR}" \
	    --prefix "${PREFIX}" \
	    ${CARGO_INSTALL_ARGS}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so

.include <bsd.port.mk>
