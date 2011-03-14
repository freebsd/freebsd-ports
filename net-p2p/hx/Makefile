# New ports collection makefile for:   hx
# Date created:        28 March 2001
# Whom:                logo@blackened.com
#
# $FreeBSD$
#

PORTNAME=	hx
PORTVERSION=	0.7.14
PORTREVISION=	1
CATEGORIES=	net-p2p
MASTER_SITES=	http://members.macconnect.com/users/j/jalex/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A text based Hotline (http://www.bigredh.com) client for Unix

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

WRKSRC=		${WRKDIR}/${PORTNAME}

GNU_CONFIGURE=	yes

MAN1=		hx.1
PLIST_FILES=	bin/hx

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hx ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/hx.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
