PORTNAME=	nast
DISTVERSION=	0.2.1-g20210616
CATEGORIES=	net

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Packet sniffer
WWW=		https://github.com/embyte0/nast

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libnet.so:net/libnet

USES=		gmake ncurses
USE_GITHUB=	yes
GH_ACCOUNT=	embyte0
GH_TAGNAME=	96f4f8edd457772485415aaf5404ea56cf2b311f

GNU_CONFIGURE=	yes
CFLAGS+=	-fcommon

PLIST_FILES=	bin/nast man/man8/nast.8.gz

post-patch:
	@${REINPLACE_CMD} 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${STAGEDIR}${MANPREFIX}/man/man8

.include <bsd.port.mk>
