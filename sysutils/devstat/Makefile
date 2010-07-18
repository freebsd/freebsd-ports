# New ports collection makefile for:	devstat
# Date created:				13 April 2008
# Whom:					Mikolaj Golub <to.my.trociny@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	devstat
PORTVERSION=	0.3.2
CATEGORIES=	sysutils
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	to.my.trociny@gmail.com
COMMENT=	Utility to display device statistics

PLIST_FILES=	bin/devstat
MAN8=		devstat.8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/devstat ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/devstat.8 ${PREFIX}/man/man8

.include <bsd.port.mk>
