# New ports collection makefile for:    cdrecord
# Version required:     1.6
# Date created:         2 November 1997
# Whom:                 jmz
#
# $Id: Makefile,v 1.9 1998/10/31 07:00:21 obrien Exp $
#

DISTNAME=	cdrecord-1.8a19
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.fokus.gmd.de/pub/unix/cdrecord/alpha/

MAINTAINER=	jmz@FreeBSD.org
WRKSRC=         ${WRKDIR}/cdrecord-1.8

MAN1=		cdrecord.1 cdda2wav.1
USE_GMAKE=	yes

do-build:
	@cd ${WRKSRC} && gmake COPTX=-DBSD_SCSI_SENSE_BUG

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/cdrecord/OBJ/i386-freebsd-cc/cdrecord \
	 ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/cdda2wav/OBJ/i386-freebsd-cc/cdda2wav \
	 ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/cdrecord/cdrecord.1 ${PREFIX}/man/man1
	@${INSTALL_MAN} ${WRKSRC}/cdrecord/cdda2wav.1 ${PREFIX}/man/man1
	@cd /dev && ln -sf /dev/rworm0.ctl scgx

.include <bsd.port.mk>
