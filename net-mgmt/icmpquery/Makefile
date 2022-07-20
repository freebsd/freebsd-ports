PORTNAME=	icmpquery
PORTVERSION=	1.0.3
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.angio.net/security/
DISTNAME=	icmpquery
EXTRACT_SUFX=	.c

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small utility for finding out time & netmask through ICMP

PLIST_FILES=	bin/icmpquery
NO_WRKSUBDIR=	YES
ALL_TARGET=	icmpquery

do-extract:
		@${CP} ${DISTDIR}/${DISTFILES} ${WRKSRC}
		@${CP} ${FILESDIR}/Makefile ${WRKSRC}

do-install:
		@${INSTALL_PROGRAM} ${WRKSRC}/icmpquery ${STAGEDIR}${PREFIX}/bin
		@${CHMOD} u+s ${STAGEDIR}${PREFIX}/bin/icmpquery

.include <bsd.port.mk>
