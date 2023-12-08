PORTNAME=	rosenpass
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.1
PORTREVISION=	1
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
		wireguard>0:net/wireguard

USES=		cargo llvm:build pkgconfig shebangfix
USE_GITHUB=	yes
CARGO_INSTALL_PATH=	rosenpass

PLIST_FILES=	bin/rosenpass \
		bin/rp \
		man/man1/rosenpass.1.gz \
		man/man1/rp.1.gz

pre-configure:
	${REINPLACE_CMD} -e 's,%%BASH%%,${LOCALBASE}/bin/bash,' ${WRKSRC}/rp

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/rp ${STAGEDIR}${PREFIX}/bin/
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/rosenpass
.for man in rp.1 rosenpass.1
	${INSTALL_MAN} ${WRKSRC}/doc/${man} ${STAGEDIR}${MANPREFIX}/man/man${man:E}/${man}
.endfor

.include <bsd.port.mk>
