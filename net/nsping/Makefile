# New ports collection makefile for:	nsping
# Date created:		04 March 2000
# Whom:			Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nsping
PORTVERSION=	0.8
CATEGORIES=	net
MASTER_SITES=	http://www.enteract.com/~tqbf/
DISTFILES=	nsping.tar.gz

MAINTAINER=	kris@FreeBSD.org

MAN8=		nsping.8

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/nsping ${PREFIX}/sbin
		${INSTALL_DATA} ${WRKSRC}/nsping.8 ${PREFIX}/man/man8

.include <bsd.port.mk>
