# New ports collection makefile for:	tripwire 1.3.1
# Date created:		Fri Mar 19 18:29:18 1999
# Whom:			Cy Schubert <Cy.Schubert@uumail.gov.bc.ca>
#
# $FreeBSD$
#

PORTNAME=	tripwire
PORTVERSION=	1.3.1
CATEGORIES=	security
DISTNAME=	Tripwire-${PORTVERSION}-1

MAINTAINER=	Cy.Schubert@uumail.gov.bc.ca

MAN5=		tw.config.5
MAN8=		siggen.8 tripwire.8
NO_CDROM=	"cannot be redistributed for more than the cost of duplication"
NO_PACKAGE=	"requires local database to be built"
RESTRICTED=	"contains crypto class algorithms"
WRKSRC=		${WRKDIR}/tw_ASR_1.3.1_src

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE='Please read http://www.tripwiresecurity.com/ for details of how to obtain the Tripwire source.  Put the file ${DISTNAME}${EXTRACT_SUFX} into the directory ${DISTDIR} and run make again.'
.endif

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

.include <bsd.port.post.mk>
