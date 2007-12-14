# New ports collection makefile for:	usbutils
# Date created:		2003-03-27
# Whom:			Bernd Walter <ticso@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	usbutil
PORTVERSION=	0.5
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.augustsson.net/pub/netbsd/ \
		http://www.mavetju.org/download/adopted/

MAINTAINER=	ticso@FreeBSD.org
COMMENT=	USB developer utilities

PLIST_FILES=	sbin/usbctl sbin/usbgen sbin/usbstats
MAN8=		usbgen.8

post-install:
	${INSTALL_MAN} ${WRKSRC}/usbgen.8 ${PREFIX}/man/man8

.include <bsd.port.mk>
