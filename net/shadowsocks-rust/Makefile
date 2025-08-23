PORTNAME=	shadowsocks-rust
DISTVERSIONPREFIX=	v
DISTVERSION=	1.23.5
CATEGORIES=	net

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Rust port of shadowsocks
WWW=		https://shadowsocks.org/ \
		https://github.com/shadowsocks/shadowsocks-rust

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libzstd.so:archivers/zstd

USES=		cargo
USE_RC_SUBR=	sslocal-rust \
		ssserver-rust

USE_GITHUB=	yes
GH_ACCOUNT=	shadowsocks

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/config.json ${STAGEDIR}${ETCDIR}/config.json.sample

.include <bsd.port.mk>
