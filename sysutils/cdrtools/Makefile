# New ports collection makefile for:	cdrtools
# Date created:		Wed Jul 25 23:30:19 CEST 2001
# Whom:			Dirk Froemberg <dirk@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME?=	cdrtools
PORTVERSION?=	2.0.3
PORTREVISION?=	1
CATEGORIES?=	sysutils audio
MASTER_SITES=	ftp://ftp.berlios.de/pub/cdrecord/ \
		ftp://ftp.cs.tu-berlin.de/pub/misc/cdrecord/ \
		ftp://ftp.gwdg.de/pub/linux/misc/cdrecord/
DISTNAME=	cdrtools-2.00.3

MAINTAINER?=	dirk@FreeBSD.org
COMMENT?=	Cdrecord and several other programs to record CD-R[W]

CONFLICTS?=	cdrtools-devel-*

.if defined(MKISOFS)
MAN8=		apple_driver.8 isoinfo.8 mkhybrid.8 mkisofs.8
.else
MAN1=		cdda2wav.1 cdrecord.1 readcd.1
.endif

USE_GMAKE=	yes
MAKE_ENV=	COPTX="-DBSD_SCSI_SENSE_BUG"
SLAVEDIRS=	sysutils/mkisofs

.if ${MACHINE_ARCH} != "i386"
post-extract:
	${LN} -sf ${WRKSRC}/RULES/i386-freebsd-cc.rul \
		${WRKSRC}/RULES/${MACHINE_ARCH}-freebsd-cc.rul
.endif

do-install:
.if defined(MKISOFS)
	@${INSTALL_PROGRAM} ${WRKSRC}/mkisofs/OBJ/${ARCH}-freebsd-cc/mkisofs \
	 ${PREFIX}/bin
	@${LN} -sf mkisofs ${PREFIX}/bin/mkhybrid
	@${INSTALL_PROGRAM} ${WRKSRC}/mkisofs/diag/OBJ/${ARCH}-freebsd-cc/devdump \
	 ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/mkisofs/diag/OBJ/${ARCH}-freebsd-cc/isodump \
	 ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/mkisofs/diag/OBJ/${ARCH}-freebsd-cc/isoinfo \
	 ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/mkisofs/diag/OBJ/${ARCH}-freebsd-cc/isovfy \
	 ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/mkisofs/apple_driver.8 ${PREFIX}/man/man8
	@${INSTALL_MAN} ${WRKSRC}/mkisofs/diag/isoinfo.8 ${PREFIX}/man/man8
	@${INSTALL_MAN} ${WRKSRC}/mkisofs/mkhybrid.8 ${PREFIX}/man/man8
	@${INSTALL_MAN} ${WRKSRC}/mkisofs/mkisofs.8 ${PREFIX}/man/man8
.else
	@${INSTALL_PROGRAM} ${WRKSRC}/cdrecord/OBJ/${ARCH}-freebsd-cc/cdrecord \
	 ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/cdda2wav/OBJ/${ARCH}-freebsd-cc/cdda2wav \
	 ${PREFIX}/bin
	@${LN} -sf cdda2wav ${PREFIX}/bin/list_audio_tracks
	@${INSTALL_PROGRAM} ${WRKSRC}/readcd/OBJ/${ARCH}-freebsd-cc/readcd \
	 ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/cdda2wav/cdda2wav.1 ${PREFIX}/man/man1
	@${INSTALL_MAN} ${WRKSRC}/cdrecord/cdrecord.1 ${PREFIX}/man/man1
	@${INSTALL_MAN} ${WRKSRC}/readcd/readcd.1 ${PREFIX}/man/man1
.endif

.include <bsd.port.mk>
