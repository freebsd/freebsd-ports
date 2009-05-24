# New ports collection makefile for:	pkg_add_it
# Date created:				05 October 2008
# Whom:					Marin Atanasov <dnaeon@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	pkg_add_it
PORTVERSION=	1.2
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://www.unix-heaven.org/ports-mgmt/

MAINTAINER=	dnaeon@gmail.com
COMMENT=	Interactive interface for the pkg_add(1) command

MAN1=		pkg_add_it.1
PLIST_FILES=	sbin/pkg_add_it

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pkg_add_it ${PREFIX}/sbin/pkg_add_it
	${INSTALL_MAN} ${WRKSRC}/pkg_add_it.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
