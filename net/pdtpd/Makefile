# New ports collection makefile for:	pdtpd
# Date created:		5 Apr 2004
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pdtpd
PORTVERSION=	0.1.20040404
CATEGORIES=	net
MASTER_SITES=	http://people.FreeBSD.org/~kuriyama/distfiles/
DISTNAME=	${PORTNAME}-20040404

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Server for the Peer Distributed Transfer Protocol (PDTP)

WRKSRC=		${WRKDIR}/${PORTNAME}
STRIP=		# Keep empty for debugging.

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pdtpd/pdtpd ${PREFIX}/sbin/pdtpd
	${INSTALL_PROGRAM} ${WRKSRC}/pdtpss/pdtpss ${PREFIX}/sbin/pdtpss
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}

.include <bsd.port.mk>
