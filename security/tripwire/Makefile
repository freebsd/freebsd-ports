# New ports collection makefile for:	tripwire
# Date created:		31 Mar 1997
# Whom:			Joe Greco <jgreco@ns.sol.net>
#
# $FreeBSD$
#

PORTNAME=	tripwire
PORTVERSION=	1.2
CATEGORIES=	security net
MASTER_SITES=	ftp://coast.cs.purdue.edu/pub/COAST/Tripwire/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	jgreco@ns.sol.net

MAN5=		tw.config.5
MAN8=		siggen.8 tripwire.8
NO_CDROM=	"cannot be redistributed for more than the cost of duplication"
NO_PACKAGE=	"requires local database to be built"
RESTRICTED=	"contains crypto class algorithms"

post-extract:
	@ (cd ${WRKDIR}; tar xf T1.2.tar)

pre-configure:
	@ ${CP} ${FILESDIR}/conf-freebsd2.h ${WRKSRC}/configs
	@ ${CP} ${FILESDIR}/tw.conf.freebsd2 ${WRKSRC}/configs/tw.conf.freebsd2

post-install:
	@ ${MKDIR} /var/adm/tcheck
	@ ${CP} ${FILESDIR}/tw.conf.freebsd2 /var/adm/tcheck/tw.config
	@ ${ECHO} Creating tripwire database
	@ (cd /var/adm/tcheck; tripwire -initialize)
.if defined(TRIPWIRE_FLOPPY) && ${TRIPWIRE_FLOPPY} == YES
	@ disklabel -w -B /dev/rfd0c fd1440
	@ newfs -u 0 -t 0 -i 196608 -m 0 -T minimum -o space /dev/rfd0c
	@ mount /dev/fd0c /mnt
	@ ${GZIP_CMD} < ${PREFIX}/bin/tripwire > /mnt/tripwire
	@ ${CP} -p /var/adm/tcheck/tw.config /mnt/tw.config
	@ ${GZIP_CMD} < /var/adm/tcheck/databases/tw.db_`hostname` \
		> /mnt/tw.db_`hostname`.gz
	@ ${CP} -p ${FILESDIR}/twcheck /mnt/twcheck
	@ ${GZIP_CMD} < /usr/bin/gunzip > /mnt/gunzip
	@ ${CHMOD} 555 /mnt/tripwire /mnt/gunzip /mnt/twcheck
	@ umount /mnt
	@ ${ECHO} Do not forget to remove and write-protect the floppy.
.endif

.include <bsd.port.mk>
