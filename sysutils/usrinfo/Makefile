# New ports collection makefile for:	usrinfo
# Date created:				28 January 2004
# Whom:					Aaron Landwehr <aaron@snaphat.com>
#
# $FreeBSD$
#

PORTNAME=	usrinfo
PORTVERSION=	.10
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER?=	aaron@snaphat.com
COMMENT=	Displays information about a user using either "<br>" or "\n" breaks

USE_BZIP2=	yes

PLIST_FILES=	bin/usrinfo

MANCOMPRESSED=	no
MAN1=		usrinfo.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/usrinfo ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/usrinfo.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
