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
MAN1=		icmpinfo.1
PLIST_FILES=	bin/icmpinfo
PORTDOCS=	README

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/icmpinfo ${PREFIX}/bin
	${CHOWN} root ${PREFIX}/bin/icmpinfo
	${CHMOD} 4555 ${PREFIX}/bin/icmpinfo
	${INSTALL_MAN} ${WRKSRC}/icmpinfo.man ${PREFIX}/man/man1/${MAN1}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
