# New ports collection makefile for:	aircrack
# Date created:				25 Nov 2005
# Whom:					Lars Engels <lars.engels@0x20.net>
#
# $FreeBSD$
#

PORTNAME=	aircrack
PORTVERSION=	2.41
CATEGORIES=	net-mgmt
MASTER_SITES=	http://mirror.arcticnetwork.ca/pub/gentoo/distfiles/ \
		http://gentoo.llarian.net/distfiles/ \
		http://gentoo.zie.pg.gda.pl/distfiles/ \
		http://www.dvo.ru/pub/distfiles/ \
		http://gentoo.nedlinux.nl/distfiles/ \
		http://bsd-geek.de/FreeBSD/distfiles/
EXTRACT_SUFX=	.tgz

MAINTAINER=	lars.engels@0x20.net
COMMENT=	Aircrack is a set of tools for auditing wireless networks

ALL_TARGET=	aircrack airdecap arpforge mergeivs pcap2ivs

PLIST_FILES=	bin/aircrack bin/airdecap bin/arpforge bin/mergeivs bin/pcap2ivs
PORTDOCS=	*

pre-fetch:
	@${CAT} ${PKGMESSAGE}

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/aircrack ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/airdecap ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/arpforge ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/mergeivs ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/pcap2ivs ${PREFIX}/bin

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.html ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DOCSDIR}/
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
