# New ports collection makefile for:	mkisofs
# Version required:	1.12b4
# Date created:		07 Aug 1996
# Whom:			jhk
#
# $FreeBSD$
#

DISTNAME=	mkisofs-1.12b5
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.fokus.gmd.de/pub/unix/cdrecord/mkisofs/ \
		ftp://ftp.gwdg.de/pub/linux/misc/cdrecord/mkisofs/ \
		ftp://ftp.cs.tu-berlin.de/pub/misc/cdrecord/mkisofs/

MAINTAINER=	dirk@FreeBSD.org

GNU_CONFIGURE=	yes
MAKE_FLAGS=	XCFLAGS='-c -I. ${CFLAGS} -DSYSTEM_ID_DEFAULT=\"FREEBSD\"' -f
ALL_TARGET=	World
MAN8=		mkisofs.8

.include <bsd.port.mk>
