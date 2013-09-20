# Created by: dom@happygiraffe.net
# $FreeBSD$

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

NO_STAGE=	yes
do-extract:
		@${MKDIR} ${WRKDIR}
		@${CP} ${DISTDIR}/${DISTFILES} ${WRKDIR}
		@${CP} ${FILESDIR}/Makefile ${WRKDIR}

do-install:
		@${INSTALL_PROGRAM} ${WRKDIR}/icmpquery ${PREFIX}/bin
		@${CHMOD} u+s ${PREFIX}/bin/icmpquery

.include <bsd.port.mk>
