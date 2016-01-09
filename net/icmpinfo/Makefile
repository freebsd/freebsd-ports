# Created by: David O'Brien (obrien@FreeBSD.org)
# $FreeBSD$

PORTNAME=	icmpinfo
PORTVERSION=	1.11
PORTREVISION=	1
CATEGORIES=	net sysutils
MASTER_SITES=	SUNSITE/system/network/admin

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Looks at the icmp messages received by the host

LICENSE=	MIT

ALL_TARGET=	# empty
PLIST_FILES=	"@(,,4555) bin/icmpinfo" \
		man/man1/icmpinfo.1.gz
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/icmpinfo ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/icmpinfo.man ${STAGEDIR}${MAN1PREFIX}/man/man1/icmpinfo.1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
