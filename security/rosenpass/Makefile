PORTNAME=	rosenpass
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.0
PORTREVISION=	1
CATEGORIES=	security

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Formally verified, post-quantum secure VPN that uses WireGuard
WWW=		https://rosenpass.eu

LICENSE=	MIT APACHE20
LICENSE_COMB=	dual
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE

BUILD_DEPENDS=	${LOCALBASE}/bin/cmake:devel/cmake-core \
		${LOCALBASE}/llvm${LLVM_DEFAULT}/lib/libclang.so:devel/llvm${LLVM_DEFAULT}
LIB_DEPENDS=	libsodium.so:security/libsodium
RUN_DEPENDS=	${LOCALBASE}/bin/bash:shells/bash

USES=		cargo
USE_GITHUB=	yes
PLIST_FILES=	bin/rosenpass \
		bin/rp \
		share/man/man1/rp.1.gz \
		share/man/man1/rosenpass.1.gz

post-patch:
	${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' ${WRKSRC}/rp

post-install:
.for MANPAGE in ${PLIST_FILES:Mshare/man/*:T}
	${INSTALL_MAN} ${WRKSRC}/doc/${MANPAGE:S/.gz//} \
		${STAGEDIR}${MANPREFIX}/share/man/man${MANPAGE:C/^[^.]*[.]//:S/.gz//}/${MANPAGE:S/.gz//}
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/rp ${STAGEDIR}${PREFIX}/bin/rp

.include <bsd.port.mk>
