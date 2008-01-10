# New ports collection makefile for:	ipgrab
# Date created:				23. January 2004
# Whom:					Aaron Zauner <az_mail@gmx.at>
#
# $FreeBSD$
#

PORTNAME=	ipgrab
PORTVERSION=	0.9.10
CATEGORIES=	net security
MASTER_SITES=	SF

MAINTAINER=	az_mail@gmx.at
COMMENT=	IPgrab is a verbose packet sniffer for UNIX hosts

BUILD_DEPENDS=	${LOCALBASE}/include/pcap.h:${PORTSDIR}/net/libpcap

GNU_CONFIGURE=	yes
INFO=		ipgrab
MAN8=		ipgrab.8
DOCS=		README AUTHORS COPYING ChangeLog \
		DEVELOPER-HOWTO INSTALL NEWS TODO

PLIST_FILES=	bin/ipgrab ${DOCS:S,^,%%DOCSDIR%%/,}
PLIST_DIRS=	%%DOCSDIR%%

do-install:
	@${INSTALL_MAN} ${MAN8:S,^,${WRKSRC}/doc/,} ${MANPREFIX}/man/man8/
	@${INSTALL_DATA} ${WRKSRC}/doc/ipgrab.info ${PREFIX}/info/
	@${INSTALL_PROGRAM} ${WRKSRC}/src/ipgrab ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
