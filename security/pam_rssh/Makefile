PORTNAME=	pam_rssh
DISTVERSIONPREFIX=v
DISTVERSION=	1.1.0
PORTREVISION=	18
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

CARGO_CRATES=	base64-0.13.1 \
		bitflags-1.3.2 \
		byteorder-1.4.3 \
		cc-1.0.79 \
		cfg-if-1.0.0 \
		error-chain-0.12.4 \
		foreign-types-0.3.2 \
		foreign-types-shared-0.1.1 \
		futures-0.1.31 \
		hostname-0.3.1 \
		itoa-1.0.6 \
		libc-0.2.140 \
		log-0.4.17 \
		match_cfg-0.1.0 \
		multisock-1.0.0 \
		num_threads-0.1.6 \
		once_cell-1.17.1 \
		openssl-0.10.55 \
		openssl-macros-0.1.0 \
		openssl-sys-0.9.90 \
		pam-bindings-0.1.1 \
		pkg-config-0.3.26 \
		proc-macro2-1.0.52 \
		pwd-1.4.0 \
		quote-1.0.26 \
		serde-1.0.157 \
		serde_derive-1.0.157 \
		syn-1.0.109 \
		syn-2.0.0 \
		syslog-6.0.1 \
		thiserror-1.0.40 \
		thiserror-impl-1.0.40 \
		time-0.3.20 \
		time-core-0.1.0 \
		time-macros-0.2.8 \
		unicode-ident-1.0.8 \
		vcpkg-0.2.15 \
		version_check-0.9.4 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	lib/pam_rssh.so

do-install:
	${INSTALL_LIB} ${CARGO_TARGET_DIR}/release/libpam_rssh.so ${STAGEDIR}${PREFIX}/lib/pam_rssh.so

.include <bsd.port.mk>
