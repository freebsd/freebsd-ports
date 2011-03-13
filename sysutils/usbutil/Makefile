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

MAINTAINER=	ports@FreeBSD.org
COMMENT=	USB developer utilities

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

PLIST_FILES=	sbin/usbctl sbin/usbgen sbin/usbstats
MAN8=		usbgen.8

post-install:
	${INSTALL_MAN} ${WRKSRC}/usbgen.8 ${PREFIX}/man/man8

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800064
IGNORE=		functionality integrated in usbconfig(8)
.endif

.include <bsd.port.post.mk>
