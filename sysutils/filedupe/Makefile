# New ports collection makefile for:	filedupe
# Date created:			Apr 10, 2001
# Whom:				Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	filedupe
PORTVERSION=	1.1
CATEGORIES=	sysutils
MASTER_SITES=	http://sammy.net/~sammy/hacks/

MAINTAINER=	mark@kyne.com.au

LIB_DEPENDS=	gdbm.2:${PORTSDIR}/databases/gdbm

do-install:
	$(INSTALL_PROGRAM) ${WRKSRC}/filedupe ${PREFIX}/bin

.include <bsd.port.mk>
