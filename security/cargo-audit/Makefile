PORTNAME=	cargo-audit
DISTVERSIONPREFIX=	${PORTNAME}/v
DISTVERSION=	0.21.2
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	security

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Audit Cargo.lock for crates with security vulnerabilities
WWW=		https://rustsec.org/

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/${PORTNAME}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/${PORTNAME}/LICENSE-MIT

# ca_root_nss must be installed until
# https://github.com/rustsec/rustsec/issues/1137 is fixed
RUN_DEPENDS=	ca_root_nss>=0:security/ca_root_nss

USES=		cargo localbase ssl
USE_GITHUB=	yes
GH_ACCOUNT=	RustSec
GH_PROJECT=	rustsec

CARGO_CARGOTOML=	${WRKSRC}/${PORTNAME}/Cargo.toml
CARGO_INSTALL_PATH=	${PORTNAME}

NO_TEST=	yes

PLIST_FILES=	bin/cargo-audit

.include <bsd.port.mk>
