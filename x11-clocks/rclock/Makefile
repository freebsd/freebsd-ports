# ex:ts=8
# Ports collection Makefile for:  rclock
# Version required:		  2.7.3
# Date created:			  24th Feburary 1997
# Whom:				  obrien@NUXI.com
#
# $FreeBSD$
#

DISTNAME=	rxvt-${VERSION}
PKGNAME=	rclock-${VERSION}
CATEGORIES=	x11-clocks
MASTER_SITES=	ftp://ftp.rxvt.org/pub/rxvt/  \
		ftp://mason.primenet.com.au/pub/rxvt/ \
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	X11/terms

MAINTAINER=	obrien@FreeBSD.org

VERSION=	2.7.3
CFLAGS+=	-DMAIL_SPOOL='\"/var/mail/\"'
USE_BZIP2=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=  yes
ALL_TARGET=	clock
MAN1=		rclock.1

.include <bsd.port.mk>
