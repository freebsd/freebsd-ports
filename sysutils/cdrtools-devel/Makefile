# New ports collection makefile for:    cdrecord
# Version required:     1.6
# Date created:         2 November 1997
# Whom:                 jmz
#
# $Id: Makefile,v 1.5 1998/03/27 23:14:05 steve Exp $
#

DISTNAME=	cdrecord-1.6
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.fokus.gmd.de/pub/unix/cdrecord/

MAINTAINER=	jmz@FreeBSD.org

RUN_DEPENDS=	mkisofs:${PORTSDIR}/sysutils/mkisofs

MAN1=		cdrecord.1
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${PKGNAME}

do-build:
	@cd ${WRKSRC}/lib && ../Gmake
	@cd ${WRKSRC}/cdrecord && ../Gmake COPTX=-DBSD_SCSI_SENSE_BUG

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/cdrecord/OBJ/i386-freebsd-cc/cdrecord \
	 ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/cdrecord/cdrecord.1 ${PREFIX}/man/man1
	@cd /dev && ln -sf /dev/rworm0.ctl scgx

.include <bsd.port.mk>
