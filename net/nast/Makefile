PORTNAME=	nast
PORTVERSION=	0.2.0
PORTREVISION=	6
CATEGORIES=	net
MASTER_SITES=	BERLIOS

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Packet sniffer

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_FreeBSD_13=	ld: error: duplicate symbol: arp_glob
BROKEN_FreeBSD_14=	ld: error: duplicate symbol: arp_glob

LIB_DEPENDS=	libnet.so:net/libnet

USES=		gmake
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/nast man/man8/nast.8.gz

post-patch:
	@${REINPLACE_CMD} 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${STAGEDIR}${MANPREFIX}/man/man8

.include <bsd.port.mk>
