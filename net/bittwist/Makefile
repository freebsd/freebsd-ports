PORTNAME=	bittwist
PORTVERSION=	4.7
DISTVERSIONPREFIX=	bsd-
CATEGORIES=	net
MASTER_SITES=	SF/bittwist/BSD/Bit-Twist%20${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Libpcap-based Ethernet packet generator, with PCAP editor
WWW=		https://bittwist.sourceforge.io/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LDFLAGS+=	-lpcap

PLIST_FILES=	bin/bittwist \
		bin/bittwiste \
		share/man/man1/bittwist.1.gz \
		share/man/man1/bittwiste.1.gz

do-build:
	${CC} ${CFLAGS} ${LDFLAGS} ${WRKSRC}/src/bittwist.c ${WRKSRC}/src/token_bucket.c -o ${WRKSRC}/src/bittwist
	${CC} ${CFLAGS} ${LDFLAGS} ${WRKSRC}/src/bittwiste.c ${WRKSRC}/src/tinymt/tinymt64.c ${WRKSRC}/src/template_pcap.c -I${WRKSRC}/src/tinymt -o ${WRKSRC}/src/bittwiste

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/bittwist ${WRKSRC}/src/bittwiste ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/doc/bittwist.1 ${WRKSRC}/doc/bittwiste.1 ${STAGEDIR}${PREFIX}/share/man/man1/

.include <bsd.port.mk>
