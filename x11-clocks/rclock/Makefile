# ex:ts=8
# Ports collection Makefile for:  rclock
# Date created:			  24th Feburary 1997
# Whom:				  obrien@NUXI.com
#
# $FreeBSD$
#

PORTNAME=	rclock
PORTVERSION=	2.7.3
CATEGORIES=	x11-clocks
MASTER_SITES=	ftp://ftp.rxvt.org/pub/rxvt/  \
		ftp://mason.primenet.com.au/pub/rxvt/ \
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	X11/terms
DISTNAME=	rxvt-${PORTVERSION}

MAINTAINER=	obrien@FreeBSD.org

CFLAGS+=	-DMAIL_SPOOL='\"/var/mail/\"'
USE_BZIP2=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=  yes
ALL_TARGET=	clock
MAN1=		rclock.1

.include <bsd.port.mk>
