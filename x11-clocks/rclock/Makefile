# ex:ts=8
# Ports collection Makefile for:  rclock
# Version required:		  2.6.1
# Date created:			  24th Feburary 1997
# Whom:				  obrien@NUXI.com
#
# $Id: Makefile,v 1.7 1999/06/24 04:43:55 obrien Exp $
#

PKGNAME=	rclock-2.6.1
DISTNAME=	rxvt-2.6.1
CATEGORIES=	x11-clocks
MASTER_SITES=	ftp://ftp.rxvt.org/pub/rxvt/  \
		ftp://mason.primenet.com.au/pub/rxvt/ \
		${MASTER_SITE_SUNSITE}

MASTER_SITE_SUBDIR=	X11/terms

MAINTAINER=	obrien@FreeBSD.org

CFLAGS+=	-DMAIL_SPOOL='\"/var/mail/\"'
USE_BZIP2=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=  yes
ALL_TARGET=	clock
MAN1=		rclock.1

.include <bsd.port.mk>
