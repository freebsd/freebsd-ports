# ex:ts=8
# Ports collection Makefile for:  rclock
# Version required:		  2.19
# Date created:			  24th Feburary 1997
# Whom:				  obrien@NUXI.com
#
# $Id: Makefile,v 1.6 1999/02/10 21:36:52 obrien Exp $
#

PKGNAME=	rclock-2.6.0
DISTNAME=	rxvt-2.6.0
CATEGORIES=	x11-clocks
MASTER_SITES=	${MASTER_SITE_SUNSITE}  \
		ftp://ftp.rxvt.org/pub/rxvt/  \
		ftp://ftp.nuclecu.unam.mx/linux/local/rxvt/  \
		ftp://tsx-11.mit.edu/pub/linux/sources/usr.bin.X11/  \
		http://wm.current.nu/files/  \
		ftp://mason.primenet.com.au/pub/rxvt/
MASTER_SITE_SUBDIR=	X11/terms

MAINTAINER=	obrien@FreeBSD.org

CFLAGS+=	-DMAIL_SPOOL='\"/var/mail/\"'
USE_BZIP2=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=  yes
ALL_TARGET=	clock
MAN1=		rclock.1

.include <bsd.port.mk>
