# New ports collection makefile for:	ident2
# Date created:				30 Nov 1999
# Whom:					rod@zort.on.ca
#
# $FreeBSD$
#

PORTNAME=	ident2
PORTVERSION=	1.07
CATEGORIES=	security net
MASTER_SITES=	http://michael.bacarella.com/projects/ident2/
DISTNAME=	ident2-v${PORTVERSION}_FINAL

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An RFC1413 identification server which also supports random replies

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
MAN8=		ident2.8
PLIST_FILES=	sbin/ident2

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ident2 ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/${MAN8} ${MANPREFIX}/man/man8/

.include <bsd.port.mk>
