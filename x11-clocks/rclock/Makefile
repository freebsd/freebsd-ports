# ex:ts=8
# Ports collection Makefile for:  rclock
# Version required:		  2.19
# Date created:			  24th Feburary 1997
# Whom:				  obrien@NUXI.com
#
# $Id: Makefile,v 1.10 1996/12/08 02:30:29 obrien Exp $
#

PKGNAME=	rclock-2.20
DISTNAME=	rxvt-2.20
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SUNSITE}  \
		ftp://ftp.nuclecu.unam.mx/linux/local/rxvt/  \
		ftp://tsx-11.mit.edu/pub/linux/sources/usr.bin.X11/
MASTER_SITE_SUBDIR=	utils/file/managers/mc/rxvt
#MASTER_SITE_SUBDIR=	X11/xutils/terms

MAINTAINER=	obrien@FreeBSD.org

CFLAGS+=	'-DMAIL_SPOOL=\"/var/mail/\"'
USE_X11=	yes
GNU_CONFIGURE=  yes
ALL_TARGET=	clock
MAN1=		rclock.1

.include <bsd.port.mk>
