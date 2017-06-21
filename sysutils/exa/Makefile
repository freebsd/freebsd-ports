# $FreeBSD$

PORTNAME=	exa
PORTVERSION=	0.6.0
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Modern replacement for ls

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENCE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	ogham
GH_TUPLE=	rust-datetime:zoneinfo-compiled:f56921ea5e9f7cf065b1480ff270a1757c1f742f:zoneinfo_compiled

PLIST_FILES=	bin/exa man/man1/exa.1.gz

CARGO_CRATES=	ansi_term-0.8.0 \
		bitflags-0.7.0 \
		byteorder-0.4.2 \
		cmake-0.1.23 \
		datetime-0.4.4 \
		gcc-0.3.46 \
		getopts-0.2.14 \
		git2-0.6.5 \
		glob-0.2.11 \
		idna-0.1.1 \
		iso8601-0.1.1 \
		lazy_static-0.2.8 \
		libc-0.2.23 \
		libgit2-sys-0.6.10 \
		libz-sys-1.0.13 \
		locale-0.2.1 \
		matches-0.1.4 \
		natord-1.0.9 \
		nom-1.2.4 \
		num-0.1.37 \
		num-bigint-0.1.37 \
		num-complex-0.1.37 \
		num-integer-0.1.34 \
		num-iter-0.1.33 \
		num-rational-0.1.36 \
		num-traits-0.1.37 \
		num_cpus-1.4.0 \
		number_prefix-0.2.7 \
		pad-0.1.4 \
		pkg-config-0.3.9 \
		rand-0.3.15 \
		rustc-serialize-0.3.24 \
		scoped_threadpool-0.1.7 \
		term_grid-0.1.5 \
		unicode-bidi-0.2.6 \
		unicode-normalization-0.1.4 \
		unicode-width-0.1.4 \
		url-1.4.0 \
		users-0.5.2

CARGO_FEATURES=		git2
CARGO_USE_GITHUB=	yes

post-install:
	${INSTALL_MAN} ${WRKSRC}/contrib/man/exa.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
