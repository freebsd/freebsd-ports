PORTNAME=	rosenpass
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.2
PORTREVISION=	11
CATEGORIES=	net net-vpn security

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Wireguard-based post-quantum VPN
WWW=		https://rosenpass.eu/

LICENSE=	MIT APACHE20
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

LIB_DEPENDS=	libsodium.so:security/libsodium
RUN_DEPENDS=	bash:shells/bash \
		wireguard-tools>0:net/wireguard-tools

USES=		cargo llvm:build pkgconfig shebangfix
USE_GITHUB=	yes
CARGO_INSTALL_PATH=	rosenpass

PLIST_FILES=	bin/rosenpass \
		bin/rp \
		share/man/man1/rosenpass.1.gz \
		share/man/man1/rp.1.gz

pre-configure:
	${REINPLACE_CMD} -e 's,%%BASH%%,${LOCALBASE}/bin/bash,' ${WRKSRC}/rp

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/rp ${STAGEDIR}${PREFIX}/bin/
.for man in rp.1 rosenpass.1
	${INSTALL_MAN} ${WRKSRC}/doc/${man} ${STAGEDIR}${PREFIX}/share/man/man${man:E}/${man}
.endfor

.include <bsd.port.mk>
