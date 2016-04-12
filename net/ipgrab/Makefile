# Created by: Aaron Zauner <az_mail@gmx.at>
# $FreeBSD$

PORTNAME=	ipgrab
PORTVERSION=	0.9.10
CATEGORIES=	net security
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IPgrab is a verbose packet sniffer for UNIX hosts

BUILD_DEPENDS=	${LOCALBASE}/include/pcap.h:net/libpcap

GNU_CONFIGURE=	yes
USE_CSTD=	gnu89
INFO=		ipgrab
DOCS=		README AUTHORS COPYING ChangeLog \
		DEVELOPER-HOWTO INSTALL NEWS TODO

PLIST_FILES=	bin/ipgrab man/man8/ipgrab.8.gz

PORTDOCS=	README AUTHORS COPYING ChangeLog DEVELOPER-HOWTO \
		INSTALL NEWS TODO

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_MAN} ${WRKSRC}/doc/ipgrab.8 ${STAGEDIR}${MANPREFIX}/man/man8/
	${INSTALL_DATA} ${WRKSRC}/doc/ipgrab.info ${STAGEDIR}${PREFIX}/info/
	${INSTALL_PROGRAM} ${WRKSRC}/src/ipgrab ${STAGEDIR}${PREFIX}/bin/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
