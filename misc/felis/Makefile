# New ports collection makefile for:	felis
# Date created:				13 May 2000
# Whom:					G. Adam Stanislav <adam@whizkidtech.net>
#
# $FreeBSD$
#

PORTNAME=	felis
PORTVERSION=	1.0
CATEGORIES=	misc
MASTER_SITES=	http://www.whizkidtech.redprince.net/fports/

MAINTAINER=	adam@redprince.net
COMMENT=	A tool which displays one or more files as a single line of text

MAN1=		felis.1
PLIST_FILES=	bin/felis

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/felis ${PREFIX}/bin
	$(INSTALL_MAN) ${WRKSRC}/felis.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
