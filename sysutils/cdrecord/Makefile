# New ports collection makefile for:    cdrecord
# Version required:     1.6
# Date created:         2 November 1997
# Whom:                 jmz
#
# $FreeBSD$
#

DISTNAME=	cdrecord-1.8a28
CATEGORIES=	sysutils audio
MASTER_SITES=	ftp://ftp.fokus.gmd.de/pub/unix/cdrecord/alpha/ \
		ftp://ftp.cs.tu-berlin.de/pub/misc/cdrecord/alpha/ \
		ftp://ftp.gwdg.de/pub/linux/misc/cdrecord/alpha/

MAINTAINER=	dirk@FreeBSD.org

WRKSRC=         ${WRKDIR}/cdrecord-1.8
MAN1=		cdrecord.1 cdda2wav.1
USE_GMAKE=	yes
MAKE_ENV=	COPTX=-DBSD_SCSI_SENSE_BUG

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/cdrecord/OBJ/i386-freebsd-cc/cdrecord \
	 ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/cdda2wav/OBJ/i386-freebsd-cc/cdda2wav \
	 ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/cdrecord/cdrecord.1 ${PREFIX}/man/man1
	@${INSTALL_MAN} ${WRKSRC}/cdda2wav/cdda2wav.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
