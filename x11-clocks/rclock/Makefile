# ex:ts=8
# Ports collection Makefile for:  rclock
# Version required:		  2.19
# Date created:			  24th Feburary 1997
# Whom:				  obrien@NUXI.com
#
# $Id: Makefile,v 1.4 1998/09/22 22:32:10 asami Exp $
#

PKGNAME=	rclock-2.4.5
DISTNAME=	rxvt-2.4.5
CATEGORIES=	x11-clocks
MASTER_SITES=	${MASTER_SITE_SUNSITE}  \
		ftp://ftp.nuclecu.unam.mx/linux/local/rxvt/  \
		ftp://tsx-11.mit.edu/pub/linux/sources/usr.bin.X11/  \
		ftp://ftp.math.fu-berlin.de/pub/rxvt/devel/
MASTER_SITE_SUBDIR=	X11/terms

MAINTAINER=	obrien@FreeBSD.org

CFLAGS+=	-DMAIL_SPOOL='\"/var/mail/\"'
USE_X_PREFIX=	yes
GNU_CONFIGURE=  yes
ALL_TARGET=	clock
MAN1=		rclock.1

.include <bsd.port.mk>
