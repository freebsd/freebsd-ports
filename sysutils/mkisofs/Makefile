# New ports collection makefile for:	mkisofs
# Date created:		07 Aug 1996
# Whom:			jhk
#
# $FreeBSD$
#

PORTNAME=	mkisofs
PORTVERSION= 	1.12
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.fokus.gmd.de/pub/unix/cdrecord/ \
		ftp://ftp.gwdg.de/pub/linux/misc/cdrecord/ \
		ftp://ftp.cs.tu-berlin.de/pub/misc/cdrecord/
DISTNAME=	cdrecord-1.8

MAINTAINER=	dirk@FreeBSD.org

MAN8=		mkisofs.8
USE_GMAKE=	yes
MAKE_ENV=	COPTX="-DBSD_SCSI_SENSE_BUG"

.if ${MACHINE_ARCH} == "alpha"
post-extract:
	${LN} -s ${WRKSRC}/RULES/i386-freebsd-cc.rul \
		${WRKSRC}/RULES/alpha-freebsd-cc.rul
.endif

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/mkisofs/OBJ/${ARCH}-freebsd-cc/mkisofs ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/mkisofs/mkisofs.8 ${PREFIX}/man/man8

.include <bsd.port.mk>
