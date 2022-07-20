PORTNAME=	createtorrent
PORTVERSION=	1.1.4
CATEGORIES=	net-p2p
MASTER_SITES=	LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Create BitTorrent files from the command line

LICENSE=	GPLv2

USES=		ssl
GNU_CONFIGURE=	yes
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

PLIST_FILES=	bin/createtorrent

post-patch:
	@${REINPLACE_CMD} 's/-lssl/-lcrypto/' ${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
