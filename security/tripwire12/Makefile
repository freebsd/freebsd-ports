# New ports collection makefile for:	tripwire
# Date created:		31 Mar 1997
# Whom:			Joe Greco <jgreco@ns.sol.net>
#
# $FreeBSD$
#

PORTNAME=	tripwire
PORTVERSION=	1.2
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.fu-berlin.de/unix/security/tripwire/old/
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	jgreco@ns.sol.net
COMMENT=	File system security and verification program

LATEST_LINK=	tripwire12
MAN5=		tw.config.5
MAN8=		siggen.8 tripwire.8
NO_CDROM=	"cannot be redistributed for more than the cost of duplication"
NO_PACKAGE=	"requires local database to be built"
USE_PERL5_BUILD=yes

TWCONFIG?=	${FILESDIR}/tw.conf.freebsd2

post-extract:
	@ (cd ${WRKDIR}; tar xpf T1.2.tar)

post-patch:
	@${PERL} -pi -e 's|/secureplace/bin|${PREFIX}/bin|g;' \
		-e 's|/usr/man|${PREFIX}/man|g;' ${WRKSRC}/Makefile

pre-configure:
	@ ${CP} ${FILESDIR}/conf-freebsd2.h ${WRKSRC}/configs
	@ ${SED} s%/kernel%`/sbin/sysctl -bn kern.bootfile`% \
		< ${TWCONFIG} \
		> ${WRKSRC}/configs/tw.conf.freebsd2

post-install:
	@ ${MKDIR} /var/adm/tcheck
	@ ${CP} ${TWCONFIG} /var/adm/tcheck/tw.config
	# Creating tripwire database
.ifndef NO_DB_BUILD
	@ (cd /var/adm/tcheck; tripwire -initialize)
.if defined(TRIPWIRE_FLOPPY) && ${TRIPWIRE_FLOPPY} == YES
	# preparing the floppy
	@ disklabel -w -B /dev/rfd0c fd1440
	@ newfs -u 0 -t 0 -i 196608 -m 0 -T minimum -o space /dev/rfd0c
	mount /dev/fd0c /mnt
	# transferring things to the floppy
	@ ${CP} -p /var/adm/tcheck/tw.config /mnt/tw.config
	@ ${GZIP_CMD} < /var/adm/tcheck/databases/tw.db_`hostname` \
		> /mnt/tw.db_`hostname`.gz
	@ ${CP} -p ${FILESDIR}/twcheck /usr/bin/gunzip \
			${PREFIX}/bin/tripwire \
		/mnt/
	@ ${CHMOD} 555 /mnt/tripwire /mnt/gunzip /mnt/twcheck
	@ umount /mnt
	# Do not forget to remove and write-protect the floppy.
.endif
.endif

.include <bsd.port.mk>
