# New ports collection makefile for:	mkisofs
# Date created:		07 Aug 1996
# Whom:			jhk
#
# $FreeBSD$
#

PORTNAME=	mkisofs
PORTVERSION=	1.12.1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.fokus.gmd.de/pub/unix/cdrecord/ \
		ftp://ftp.gwdg.de/pub/linux/misc/cdrecord/ \
		ftp://ftp.cs.tu-berlin.de/pub/misc/cdrecord/
DISTNAME=	cdrecord-1.8.1

PATCH_SITES=	${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=	dirk
PATCHFILES=	apple_driver.patch

MAINTAINER=	dirk@FreeBSD.org

MAN8=		apple_driver.8 isoinfo.8 mkhybrid.8 mkisofs.8
USE_GMAKE=	yes
MAKE_ENV=	COPTX="-DBSD_SCSI_SENSE_BUG"

.if ${MACHINE_ARCH} == "alpha"
post-extract:
	${LN} -s ${WRKSRC}/RULES/i386-freebsd-cc.rul \
		${WRKSRC}/RULES/alpha-freebsd-cc.rul
.endif

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/mkisofs/OBJ/${ARCH}-freebsd-cc/mkisofs ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/mkhybrid/OBJ/${ARCH}-freebsd-cc/mkhybrid ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/mkhybrid/OBJ/${ARCH}-freebsd-cc/apple_driver ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/mkisofs/diag/OBJ/${ARCH}-freebsd-cc/devdump ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/mkisofs/diag/OBJ/${ARCH}-freebsd-cc/isodump ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/mkisofs/diag/OBJ/${ARCH}-freebsd-cc/isoinfo ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/mkisofs/diag/OBJ/${ARCH}-freebsd-cc/isovfy ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/mkisofs/mkisofs.8 ${PREFIX}/man/man8
	@${INSTALL_MAN} ${WRKSRC}/mkhybrid/mkhybrid.8 ${PREFIX}/man/man8
	@${INSTALL_MAN} ${WRKSRC}/mkhybrid/apple_driver.8 ${PREFIX}/man/man8
	@${INSTALL_MAN} ${WRKSRC}/mkisofs/diag/isoinfo.8 ${PREFIX}/man/man8

.include <bsd.port.mk>
