# New ports collection makefile for:	libpdtp
# Date created:		5 Apr 2004
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libpdtp
PORTVERSION=	0.1.20040325
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	libpdtp
DISTNAME=	${PORTNAME}-M1-pre2

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Client library for Peer Distributed Transfer Protocol (PDTP)

WRKSRC=		${WRKDIR}/${PORTNAME}
HAS_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
CFLAGS+=	-fpic

do-install:
	${INSTALL_DATA} ${WRKSRC}/libpdtp.* ${PREFIX}/lib

.include <bsd.port.mk>
