PORTNAME=	pam_rssh
DISTVERSIONPREFIX=v
DISTVERSION=	1.0.0-rc1
PORTREVISION=	2
CATEGORIES=	security

MAINTAINER=	romain@FreeBSD.org
COMMENT=	Remote sudo authenticated via ssh-agent
WWW=		https://github.com/z4yx/pam_rssh

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo ssl
USE_GITHUB=	yes

GH_ACCOUNT=	z4yx
GH_PROJECT=	ssh-agent.rs:sshagent
GH_TAGNAME=	91894139966e01941f17386a84c6b35e6ea155b8:sshagent
GH_SUBDIR=	dep/ssh-agent.rs:sshagent

CARGO_CRATES=	autocfg-1.1.0 \
		base64-0.13.1 \
		bitflags-1.3.2 \
		byteorder-1.4.3 \
		cc-1.0.78 \
		cfg-if-1.0.0 \
		error-chain-0.12.4 \
		foreign-types-0.3.2 \
		foreign-types-shared-0.1.1 \
		futures-0.1.31 \
		libc-0.2.139 \
		log-0.4.17 \
		multisock-1.0.0 \
		once_cell-1.17.0 \
		openssl-0.10.45 \
		openssl-macros-0.1.0 \
		openssl-sys-0.9.80 \
		pam-bindings-0.1.1 \
		pkg-config-0.3.26 \
		proc-macro2-1.0.49 \
		pwd-1.4.0 \
		quote-1.0.23 \
		serde-1.0.152 \
		serde_derive-1.0.152 \
		syn-1.0.107 \
		syslog-5.0.0 \
		thiserror-1.0.38 \
		thiserror-impl-1.0.38 \
		time-0.1.45 \
		unicode-ident-1.0.6 \
		vcpkg-0.2.15 \
		version_check-0.9.4 \
		wasi-0.10.0+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	lib/pam_rssh.so

do-install:
	${INSTALL_LIB} ${CARGO_TARGET_DIR}/${CARGO_BUILD_TARGET}/release/libpam_rssh.so ${STAGEDIR}${PREFIX}/lib/pam_rssh.so

.include <bsd.port.mk>
