# New ports collection makefile for:    mkisofs
# Version required:     1.11.1
# Date created:         07 Aug 1996
# Whom:                 jkh
#
# $Id: Makefile,v 1.7 1998/09/03 18:51:24 obrien Exp $
#

DISTNAME=       mkisofs-1.11.3
CATEGORIES=	sysutils
MASTER_SITES=   ftp://ftp.cdrom.com/pub/linux/tsx-11/packages/mkisofs/

GNU_CONFIGURE=	yes
MAKE_FLAGS=	XCFLAGS='-c -I. ${CFLAGS} -DSYSTEM_ID_DEFAULT=\"FREEBSD\"' -f
ALL_TARGET=	World
MAN8=		mkisofs.8

.include <bsd.port.mk>
