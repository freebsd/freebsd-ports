PORTNAME=	rsclock
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.4
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simple terminal clock written in Rust
WWW=		https://github.com/valebes/rsClock

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	valebes
GH_PROJECT=	rsClock

CARGO_CRATES=	autocfg-0.1.6 \
		chrono-0.4.7 \
		libc-0.2.62 \
		num-integer-0.1.41 \
		num-traits-0.2.8 \
		numtoa-0.1.0 \
		redox_syscall-0.1.56 \
		redox_termios-0.1.1 \
		termion-1.5.3 \
		time-0.1.42 \
		winapi-0.3.8 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
