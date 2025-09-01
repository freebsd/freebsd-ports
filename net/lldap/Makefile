PORTNAME=	lldap
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.1
PORTREVISION=	3
CATEGORIES=	net

MAINTAINER=	aokblast@FreeBSD.org
COMMENT=	Light LDAP implementation for authentication
WWW=		https://github.com/lldap/lldap

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	gzip:archivers/gzip \
		wasm-pack:www/wasm-pack \
		wasm-bindgen:www/wasm-bindgen-cli
LIB_DEPENDS=	libzstd.so:archivers/zstd

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	inejge:ldap3
GH_PROJECT=	ldap3:ldap3
GH_SUBDIR=	third_party/ldap3:ldap3
GH_TAGNAME=	ba38bc573d63b:ldap3

CARGO_INSTALL_PATH=	server set-password migration-tool

USERS=		ldap
GROUPS=		ldap

post-build:
	cd ${WRKSRC} && WASM_PACK_CACHE=.wasm-pack-cache ./app/build.sh

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lldap_server/app
	${INSTALL_SCRIPT} ${WRKSRC}/example_configs/freebsd/rc.d_lldap ${STAGEDIR}${PREFIX}/etc/rc.d/lldap
	cd ${WRKSRC}/app && \
		${COPYTREE_SHARE} pkg ${STAGEDIR}${PREFIX}/lldap_server/app && \
		${COPYTREE_SHARE} static ${STAGEDIR}${PREFIX}/lldap_server/app && \
		${CP} index.html ${STAGEDIR}${PREFIX}/lldap_server/app
	${INSTALL_PROGRAM} ${STAGEDIR}${PREFIX}/bin/lldap ${STAGEDIR}${PREFIX}/lldap_server
	${MKDIR} ${STAGEDIR}${PREFIX}/share/lldap
	${INSTALL_DATA} ${WRKSRC}/lldap_config.docker_template.toml ${STAGEDIR}${PREFIX}/share/lldap/ldap_config.toml.example

.include <bsd.port.mk>
