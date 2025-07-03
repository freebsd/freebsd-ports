PORTNAME=	castor
DISTVERSION=	0.8.16
PORTREVISION=	45
CATEGORIES=	www
MASTER_SITES=	https://git.sr.ht/~julienxx/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	kraileth@elderlinux.org
COMMENT=	Browser for text-based protocols like Gemini and Gopher using GTK
WWW=		https://git.sr.ht/~julienxx/castor

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo desktop-file-utils gnome ssl
USE_GNOME=	cairo gdkpixbuf glib20 gtk30

CARGO_CRATES=	aho-corasick-0.7.13 \
		ansi-parser-0.6.5 \
		arrayref-0.3.6 \
		arrayvec-0.5.1 \
		atk-0.8.0 \
		atk-sys-0.9.1 \
		autocfg-1.0.1 \
		base64-0.12.3 \
		bitflags-1.2.1 \
		blake2b_simd-0.5.10 \
		cairo-rs-0.8.1 \
		cairo-sys-rs-0.9.2 \
		cc-1.0.60 \
		cfg-if-0.1.10 \
		constant_time_eq-0.1.5 \
		core-foundation-0.7.1 \
		core-foundation-sys-0.7.2 \
		crossbeam-utils-0.7.2 \
		dirs-3.0.1 \
		dirs-sys-0.3.5 \
		foreign-types-0.3.2 \
		foreign-types-shared-0.1.1 \
		futures-0.3.6 \
		futures-channel-0.3.6 \
		futures-core-0.3.6 \
		futures-executor-0.3.6 \
		futures-io-0.3.6 \
		futures-macro-0.3.6 \
		futures-task-0.3.6 \
		futures-util-0.3.6 \
		gdk-0.12.1 \
		gdk-pixbuf-0.8.0 \
		gdk-pixbuf-sys-0.9.1 \
		gdk-sys-0.9.1 \
		getrandom-0.1.15 \
		gio-0.8.1 \
		gio-sys-0.9.1 \
		glib-0.9.3 \
		glib-macros-0.10.1 \
		glib-sys-0.9.1 \
		gobject-sys-0.9.1 \
		gtk-0.8.0 \
		gtk-sys-0.9.2 \
		idna-0.2.0 \
		lazy_static-1.4.0 \
		libc-0.2.79 \
		linkify-0.4.0 \
		log-0.4.11 \
		matches-0.1.8 \
		memchr-2.3.3 \
		native-tls-0.2.4 \
		nom-4.2.3 \
		once_cell-1.4.1 \
		open-1.4.0 \
		openssl-0.10.30 \
		openssl-probe-0.1.2 \
		openssl-sys-0.9.58 \
		pango-0.8.0 \
		pango-sys-0.9.1 \
		percent-encoding-2.1.0 \
		pkg-config-0.3.18 \
		pin-project-0.4.26 \
		pin-project-internal-0.4.26 \
		pin-utils-0.1.0 \
		proc-macro2-1.0.24 \
		proc-macro-hack-0.5.18 \
		proc-macro-nested-0.1.6 \
		ppv-lite86-0.2.9 \
		quote-1.0.7 \
		rand-0.7.3 \
		rand_chacha-0.2.2 \
		rand_core-0.5.1 \
		rand_hc-0.2.0 \
		redox_syscall-0.1.57 \
		redox_users-0.3.5 \
		regex-1.3.9 \
		regex-syntax-0.6.18 \
		remove_dir_all-0.5.3 \
		rust-argon2-0.8.2 \
		schannel-0.1.19 \
		security-framework-0.4.4 \
		security-framework-sys-0.4.3 \
		serde-1.0.116 \
		serde_derive-1.0.116 \
		slab-0.4.2 \
		syn-1.0.42 \
		system-deps-1.3.2 \
		tempfile-3.1.0 \
		textwrap-0.12.1 \
		tinyvec-0.3.4 \
		thiserror-1.0.21 \
		thread_local-1.0.1 \
		toml-0.5.6 \
		unicode-bidi-0.3.4 \
		unicode-normalization-0.1.13 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.1 \
		url-2.1.1 \
		vcpkg-0.2.10 \
		version_check-0.1.5 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/castor \
		share/applications/Castor.desktop \
		share/examples/castor/castor_settings.toml.example \
		share/pixmaps/org.typed-hole.castor.svg

SUB_FILES=	pkg-message

.include <bsd.port.options.mk>

.if ( ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400092 && ${SSL_DEFAULT} == base ) || ${SSL_DEFAULT:Mopenssl} || ${SSL_DEFAULT:Mopenssl3*}
BROKEN_SSL=	base openssl openssl31
BROKEN_SSL_REASON=	Fails to detect OpenSSL 3.0.0 library
.endif

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/examples/castor
	${INSTALL_DATA} ${WRKSRC}/data/Castor.desktop ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/data/castor_settings.toml.example ${STAGEDIR}${PREFIX}/share/examples/castor
	${INSTALL_DATA} ${WRKSRC}/data/org.typed-hole.castor.svg ${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
