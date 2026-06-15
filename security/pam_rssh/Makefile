PORTNAME=	pam_rssh
DISTVERSIONPREFIX=v
DISTVERSION=	1.2.1
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
GH_TAGNAME=	802b94ccf2e00ac33a3863300d0769f02b62d807:sshagent
GH_SUBDIR=	dep/ssh-agent.rs:sshagent

CARGO_CRATES=	base64-0.22.1 \
		bitflags-2.11.1 \
		byteorder-1.5.0 \
		cc-1.2.62 \
		cfg-if-1.0.4 \
		deranged-0.5.8 \
		find-msvc-tools-0.1.9 \
		foreign-types-0.3.2 \
		foreign-types-shared-0.1.1 \
		futures-0.1.31 \
		hostname-0.4.2 \
		itoa-1.0.18 \
		libc-0.2.186 \
		log-0.4.30 \
		memchr-2.8.0 \
		multisock-1.0.0 \
		num-conv-0.2.2 \
		num_threads-0.1.7 \
		openssl-0.10.80 \
		openssl-macros-0.1.1 \
		openssl-sys-0.9.116 \
		pam-bindings-0.2.1 \
		pkg-config-0.3.33 \
		powerfmt-0.2.0 \
		proc-macro2-1.0.106 \
		pwd-1.4.0 \
		quote-1.0.45 \
		serde-1.0.228 \
		serde_core-1.0.228 \
		serde_derive-1.0.228 \
		shlex-1.3.0 \
		subst-0.3.8 \
		syn-2.0.117 \
		syslog-7.0.0 \
		thiserror-1.0.69 \
		thiserror-impl-1.0.69 \
		time-0.3.47 \
		time-core-0.1.8 \
		time-macros-0.2.27 \
		unicode-ident-1.0.24 \
		unicode-width-0.1.14 \
		vcpkg-0.2.15 \
		windows-link-0.2.1

PLIST_FILES=	lib/pam_rssh.so

do-install:
.ifdef WITH_DEBUG
	${INSTALL_LIB} ${CARGO_TARGET_DIR}/debug/libpam_rssh.so ${STAGEDIR}${PREFIX}/lib/pam_rssh.so
.else
	${INSTALL_LIB} ${CARGO_TARGET_DIR}/release/libpam_rssh.so ${STAGEDIR}${PREFIX}/lib/pam_rssh.so
.endif

.include <bsd.port.mk>
