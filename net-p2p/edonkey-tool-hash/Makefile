PORTNAME=	edonkey
PORTVERSION=	0.4.0
CATEGORIES=	net-p2p
MASTER_SITES=	SF/ed2k-tools/ed2k_hash/${PORTVERSION}
PKGNAMESUFFIX=	-tool-hash
DISTNAME=	ed2k_hash-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Both calculates 'eDonkey/Overnet hashes' producing ed2k:// file links

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

PLIST_FILES=	bin/edonkey-tool-hash
GNU_CONFIGURE=	yes

WRKSRC=	${WRKDIR}/ed2k_hash-${PORTVERSION}

post-patch:
# respect CFLAGS
	@${REINPLACE_CMD} -E -e \
		's|-O2||' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

do-install:
# uphold POLA, do not change binary name
	@${INSTALL_PROGRAM} ${WRKSRC}/ed2k_hash/ed2k_hash \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}${PKGNAMESUFFIX}

.include <bsd.port.mk>
