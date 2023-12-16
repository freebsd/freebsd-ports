PORTNAME=	cargo-audit
DISTVERSIONPREFIX=	${PORTNAME}/v
DISTVERSION=	0.18.3
PORTREVISION=	2
CATEGORIES=	security

MAINTAINER=	mikael@FreeBSD.org
COMMENT=	Audit Cargo.lock for crates with security vulnerabilities
WWW=		https://rustsec.org/

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

LIB_DEPENDS=	libgit2.so:devel/libgit2 \
		libssh2.so:security/libssh2

USES=		cargo localbase ssl
USE_GITHUB=	yes
GH_ACCOUNT=	RustSec
GH_PROJECT=	rustsec

NO_TEST=	yes

PLIST_FILES=	bin/cargo-audit

WRKSRC_SUBDIR=	cargo-audit

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/cargo-audit

.include <bsd.port.mk>
