PORTNAME=	acmed
DISTVERSIONPREFIX=	v
DISTVERSION=	0.25.0
CATEGORIES=	security

MAINTAINER=	gareev@aydar.me
COMMENT=	ACME (RFC 8555) client daemon written in Rust
WWW=		https://github.com/breard-r/acmed

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE-2.0.txt
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT.txt

USES=		cargo ssl
USE_GITHUB=	yes
GH_ACCOUNT=	breard-r
USE_RC_SUBR=	acmed

CARGO_FEATURES=		openssl_dyn
CARGO_INSTALL_PATH=	./acmed ./tacd
CARGO_ENV=		RUNSTATEDIR="/var/run" \
			SYSCONFDIR="${PREFIX}/etc" \
			VARLIBDIR="/var/db"

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/en/acmed.8 ${STAGEDIR}${PREFIX}/share/man/man8/
	${INSTALL_MAN} ${WRKSRC}/man/en/acmed.toml.5 ${STAGEDIR}${PREFIX}/share/man/man5/
	${INSTALL_MAN} ${WRKSRC}/man/en/tacd.8 ${STAGEDIR}${PREFIX}/share/man/man8/
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/acmed
	${MKDIR} ${STAGEDIR}/var/db/acmed/accounts ${STAGEDIR}/var/db/acmed/certs
	${INSTALL_DATA} ${WRKSRC}/acmed/config/acmed.toml ${STAGEDIR}${PREFIX}/etc/acmed/acmed.toml.sample
	${INSTALL_DATA} ${WRKSRC}/acmed/config/default_hooks.toml ${STAGEDIR}${PREFIX}/etc/acmed/default_hooks.toml.sample
	${INSTALL_DATA} ${WRKSRC}/acmed/config/letsencrypt.toml ${STAGEDIR}${PREFIX}/etc/acmed/letsencrypt.toml.sample

.include <bsd.port.mk>
