# New ports collection makefile for:    splitmpg
# Date created:         Wed Jul 31 21:59:42 CDT 1996
# Whom:                 erich@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	splitmpg
PORTVERSION=	1.0
CATEGORIES=	multimedia
MASTER_SITES=	http://member.netease.com/~inetsoft/downloads/sourcecode/multimedia/mpeg/unix/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Splits an ISO 11172-1 into its components

NO_WRKSUBDIR=	yes
MAKEFILE=	makefile
MAN1=		splitmpeg.1
PLIST_FILES=	bin/splitmpeg

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/splitmpeg ${PREFIX}/bin
	${INSTALL_MAN} ${FILESDIR}/splitmpeg.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
