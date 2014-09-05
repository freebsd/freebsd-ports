# Created by: David O'Brien (obrien@FreeBSD.org)
# $FreeBSD$

PORTNAME=	icmpinfo
PORTVERSION=	1.11
CATEGORIES=	net sysutils
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	system/network/admin

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Looks at the icmp messages received by the host

ALL_TARGET=	
PLIST_FILES=	"@(,,4555) bin/icmpinfo" \
		man/man1/icmpinfo.man.gz
PORTDOCS=	README

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/icmpinfo ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/icmpinfo.man ${STAGEDIR}${PREFIX}/man/man1/${MAN1}

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
