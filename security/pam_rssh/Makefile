PORTNAME=	pam_rssh
DISTVERSIONPREFIX=v
DISTVERSION=	1.2.0
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
		bitflags-2.6.0 \
		byteorder-1.5.0 \
		cc-1.1.15 \
		cfg-if-1.0.0 \
		deranged-0.3.11 \
		foreign-types-0.3.2 \
		foreign-types-shared-0.1.1 \
		futures-0.1.31 \
		hostname-0.4.0 \
		itoa-1.0.11 \
		libc-0.2.158 \
		log-0.4.22 \
		memchr-2.7.4 \
		multisock-1.0.0 \
		num-conv-0.1.0 \
		num_threads-0.1.7 \
		once_cell-1.19.0 \
		openssl-0.10.66 \
		openssl-macros-0.1.1 \
		openssl-sys-0.9.103 \
		pam-bindings-0.1.1 \
		pkg-config-0.3.30 \
		powerfmt-0.2.0 \
		proc-macro2-1.0.86 \
		pwd-1.4.0 \
		quote-1.0.37 \
		serde-1.0.209 \
		serde_derive-1.0.209 \
		shlex-1.3.0 \
		subst-0.3.3 \
		syn-2.0.77 \
		syslog-7.0.0 \
		thiserror-1.0.63 \
		thiserror-impl-1.0.63 \
		time-0.3.36 \
		time-core-0.1.2 \
		time-macros-0.2.18 \
		unicode-ident-1.0.12 \
		unicode-width-0.1.13 \
		vcpkg-0.2.15 \
		windows-0.52.0 \
		windows-core-0.52.0 \
		windows-targets-0.52.6 \
		windows_aarch64_gnullvm-0.52.6 \
		windows_aarch64_msvc-0.52.6 \
		windows_i686_gnu-0.52.6 \
		windows_i686_gnullvm-0.52.6 \
		windows_i686_msvc-0.52.6 \
		windows_x86_64_gnu-0.52.6 \
		windows_x86_64_gnullvm-0.52.6 \
		windows_x86_64_msvc-0.52.6

PLIST_FILES=	lib/pam_rssh.so

do-install:
	${INSTALL_LIB} ${CARGO_TARGET_DIR}/release/libpam_rssh.so ${STAGEDIR}${PREFIX}/lib/pam_rssh.so

.include <bsd.port.mk>
