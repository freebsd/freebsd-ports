# New ports collection makefile for:	mkisofs
# Version required:	1.12b5
# Date created:		07 Aug 1996
# Whom:			jhk
#
# $FreeBSD$
#

DISTNAME=	cdrecord-1.8a33
PKGNAME=	mkisofs-${VERSION}
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.fokus.gmd.de/pub/unix/cdrecord/alpha/ \
		ftp://ftp.gwdg.de/pub/linux/misc/cdrecord/alpha/ \
		ftp://ftp.cs.tu-berlin.de/pub/misc/cdrecord/alpha/

MAINTAINER=	dirk@FreeBSD.org

VERSION=	1.12b5
WRKSRC=		${WRKDIR}/cdrecord-1.8
USE_GMAKE=	yes
MAKE_ENV=	COPTX="-DBSD_SCSI_SENSE_BUG -DHAVE_SIZE_T"
MAN8=		mkisofs.8

.if ${MACHINE_ARCH} == "alpha"
post-extract:
	${LN} -s ${WRKSRC}/RULES/i386-freebsd-cc.rul \
		${WRKSRC}/RULES/alpha-freebsd-cc.rul
.endif

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/mkisofs-${VERSION}/OBJ/${ARCH}-freebsd-cc/mkisofs ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/mkisofs-${VERSION}/mkisofs.8 ${PREFIX}/man/man8

.include <bsd.port.mk>
