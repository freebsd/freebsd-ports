# New ports collection makefile for:	icmpquery
# Date created:				Jan 7 1999
# Whom:					dom@myrddin.demon.co.uk
#
# $FreeBSD$
#

PORTNAME=	icmpquery
PORTVERSION=	1.0.3
CATEGORIES=	net
MASTER_SITES=	http://www.angio.net/security/
DISTNAME=	icmpquery
EXTRACT_SUFX=	.c

MAINTAINER=	dom@myrddin.demon.co.uk

NO_WRKSUBDIR=	YES
ALL_TARGET=	icmpquery

do-extract:
		@${MKDIR} ${WRKDIR}
		@${CP} ${DISTDIR}/${DISTFILES} ${WRKDIR}
		@${CP} ${FILESDIR}/Makefile ${WRKDIR}

do-install:
		@${INSTALL_PROGRAM} ${WRKDIR}/icmpquery ${PREFIX}/bin
		@${CHMOD} u+s ${PREFIX}/bin/icmpquery

.include <bsd.port.mk>
