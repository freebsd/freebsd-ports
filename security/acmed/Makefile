PORTNAME=	acmed
DISTVERSIONPREFIX=	v
DISTVERSION=	0.21.0
PORTREVISION=	22
CATEGORIES=	security

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ACME (RFC 8555) client daemon written in Rust
WWW=		https://github.com/breard-r/acmed

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE-2.0.txt
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT.txt

USES=		cargo ssl
USE_GITHUB=	yes
GH_ACCOUNT=	breard-r

CARGO_ENV=	VARLIBDIR="/var/db" SYSCONFDIR="$(PREFIX)/etc" RUNSTATEDIR="/var/run"
CARGO_FEATURES=	openssl_dyn
CARGO_INSTALL_PATH=	./acmed ./tacd

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/en/acmed.8 ${STAGEDIR}${PREFIX}/share/man/man8/
	${INSTALL_MAN} ${WRKSRC}/man/en/acmed.toml.5 ${STAGEDIR}${PREFIX}/share/man/man5/
	${INSTALL_MAN} ${WRKSRC}/man/en/tacd.8 ${STAGEDIR}${PREFIX}/share/man/man8/
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/acmed
	${INSTALL_DATA} ${WRKSRC}/acmed/config/acmed.toml ${STAGEDIR}${PREFIX}/etc/acmed/acmed.toml.sample
	${INSTALL_DATA} ${WRKSRC}/acmed/config/default_hooks.toml ${STAGEDIR}${PREFIX}/etc/acmed/default_hooks.toml.sample
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/acmed/accounts
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/acmed/certs

.include <bsd.port.mk>
