# $FreeBSD$

PORTNAME=	boringtun
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.0
PORTREVISION=	4
CATEGORIES=	net

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	b10df0ef427cea425f6eeedb372da372055de308.patch:-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CloudFlares Userspace WireGuard implementation in Rust

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

IGNORE=		has unclear project status because the only release was \
		silently deleted upstream

RUN_DEPENDS=	wg-quick:net/wireguard

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	cloudflare

CARGO_CRATES=	ascii-0.9.1 \
		autocfg-0.1.2 \
		backtrace-0.3.14 \
		backtrace-sys-0.1.28 \
		base64-0.9.3 \
		bitflags-1.0.4 \
		boxfnonce-0.1.1 \
		byteorder-1.3.1 \
		cc-1.0.30 \
		cesu8-1.1.0 \
		cfg-if-0.1.7 \
		chrono-0.4.6 \
		clap-2.32.0 \
		combine-3.6.7 \
		daemonize-0.4.1 \
		either-1.5.1 \
		error-chain-0.12.0 \
		hex-0.3.2 \
		jni-0.10.2 \
		jni-sys-0.3.0 \
		lazy_static-1.3.0 \
		libc-0.2.50 \
		log-0.4.6 \
		memchr-2.2.0 \
		num-integer-0.1.39 \
		num-traits-0.2.6 \
		redox_syscall-0.1.51 \
		ring-0.14.6 \
		rustc-demangle-0.1.13 \
		safemem-0.3.0 \
		same-file-1.0.4 \
		spin-0.5.0 \
		strsim-0.7.0 \
		textwrap-0.10.0 \
		time-0.1.42 \
		unicode-width-0.1.5 \
		unreachable-1.0.0 \
		untrusted-0.6.2 \
		void-1.0.2 \
		walkdir-2.2.7 \
		winapi-0.3.6 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.2 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/${PORTNAME}

post-patch:
	${MV} ${WRKSRC}/src/device/tun_darwin.rs ${WRKSRC}/src/device/tun_bsd.rs

.include <bsd.port.mk>
