# Created by: Joe Greco <jgreco@ns.sol.net>
# $FreeBSD$

PORTNAME=	tripwire
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	NETBSD
PKGNAMESUFFIX=	12

MAINTAINER=	cy@FreeBSD.org
COMMENT=	File system security and verification program

BROKEN=		unfetchable
DEPRECATED=	unfetchable
EXPIRATION_DATE=	2018-07-31
NO_CDROM=	cannot be redistributed for more than the cost of duplication
NO_PACKAGE=	requires local database to be built
ONLY_FOR_ARCHS=	i386
ONLY_FOR_ARCHS_REASON=	Unknown BYTEORDER
USES=		perl5
USE_PERL5=	build
MAKE_JOBS_UNSAFE=yes

.include <bsd.port.pre.mk>

TDATADIR=	${STAGEDIR}/var/local/tcheck
MAKE_ARGS=	BINDIR=${STAGEDIR}${PREFIX}/bin \
		MANDIR=${STAGEDIR}${PREFIX}/man \
		DATADIR=${DATADIR}
NO_DB_BUILD=	yes

TWCONFIG?=	${FILESDIR}/tw.conf.freebsd8

post-extract:
	@ (cd ${WRKDIR}; tar xpf T1.2.tar)

post-patch:
	${FIND} ${WRKSRC} -type f | ${XARGS} ${REINPLACE_CMD} -e \
	    's|bs_ntohl|ntohl|g;s|bs_htonl|htonl|g'

pre-configure:
	@ ${CP} ${FILESDIR}/conf-freebsd8.h ${WRKSRC}/configs
	@ ${CP} ${TWCONFIG} ${WRKSRC}/configs/tw.conf.freebsd8

post-install:
	@ ${MKDIR} ${TDATADIR}
	@ ${CP} ${TWCONFIG} /${TDATADIR}/tw.config.dist
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

.include <bsd.port.post.mk>
