# New ports collection makefile for:    mkisofs
# Version required:     1.0.5
# Date created:         07 Aug 1996
# Whom:                 jkh
#
# $Id: Makefile,v 1.3 1997/01/06 12:13:31 jkh Exp $
#

DISTNAME=       mkisofs-1.05
CATEGORIES=	sysutils
MASTER_SITES=   ftp://ftp.cdrom.com/pub/linux/tsx-11/BETA/cdrom/

NO_WRKSUBDIR=   yes     
HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	Configure
ALL_TARGET=
MAKE_FLAGS=	CFLAGS='-c ${CFLAGS} -DSYSTEM_ID_DEFAULT=\"FREEBSD\"' -f
MAN8=		mkisofs.8

.include <bsd.port.mk>
