# New ports collection makefile for:    mkisofs
# Version required:     1.11.1
# Date created:         07 Aug 1996
# Whom:                 jkh
#
# $Id: Makefile,v 1.8 1998/09/04 00:15:45 obrien Exp $
#

DISTNAME=       mkisofs-1.11.3
CATEGORIES=	sysutils
MASTER_SITES=   ftp://ftp.cdrom.com/pub/linux/tsx-11/packages/mkisofs/ \
		ftp://ftp.fokus.gmd.de/pub/unix/cdrecord/mkisofs/

MAINTAINER=	ports@FreeBSD.ORG

GNU_CONFIGURE=	yes
MAKE_FLAGS=	XCFLAGS='-c -I. ${CFLAGS} -DSYSTEM_ID_DEFAULT=\"FREEBSD\"' -f
ALL_TARGET=	World
MAN8=		mkisofs.8

.include <bsd.port.mk>
