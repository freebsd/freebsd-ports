# New ports collection makefile for:    cdrecord
# Date created:         2 November 1997
# Whom:                 jmz
#
# $FreeBSD$
#

PORTNAME=	cdrecord
PORTVERSION=	1.9
CATEGORIES=	sysutils audio
MASTER_SITES=	ftp://ftp.fokus.gmd.de/pub/unix/cdrecord/ \
		ftp://ftp.cs.tu-berlin.de/pub/misc/cdrecord/ \
		ftp://ftp.gwdg.de/pub/linux/misc/cdrecord/

MAINTAINER=	dirk@FreeBSD.org

MAN1=		cdrecord.1 cdda2wav.1 readcd.1
USE_GMAKE=	yes
MAKE_ENV=	COPTX="-DBSD_SCSI_SENSE_BUG"

.if ${MACHINE_ARCH} == "alpha"
post-extract:
	${LN} -s ${WRKSRC}/RULES/i386-freebsd-cc.rul \
		${WRKSRC}/RULES/alpha-freebsd-cc.rul
.endif

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/cdrecord/OBJ/${ARCH}-freebsd-cc/cdrecord \
	 ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/cdda2wav/OBJ/${ARCH}-freebsd-cc/cdda2wav \
	 ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/misc/OBJ/${ARCH}-freebsd-cc/readcd \
	 ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/cdrecord/cdrecord.1 ${PREFIX}/man/man1
	@${INSTALL_MAN} ${WRKSRC}/cdda2wav/cdda2wav.1 ${PREFIX}/man/man1
	@${INSTALL_MAN} ${WRKSRC}/misc/readcd.1 ${PREFIX}/man/man1
	@${LN} -sf ${PREFIX}/bin/cdda2wav ${PREFIX}/bin/list_audio_tracks

.include <bsd.port.mk>
