# New ports collection makefile for:	aide
# Date created:				Tue Jan  4 11:45:29 PST 2000
# Whom:					Cy Schubert (Cy.Schubert@uumail.gov.bc.ca)
#
# $FreeBSD$
#

PORTNAME=	aide
PORTVERSION=	0.7
CATEGORIES=	security
MASTER_SITES=	http://www.cs.tut.fi/~rammer/ \
		ftp://ftp.cs.tut.fi/pub/src/gnu/

MAINTAINER=	Cy.Schubert@uumail.gov.bc.ca

LIB_DEPENDS=	mhash.2:${PORTSDIR}/security/mhash

USE_BISON=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-mhash \
		--with-zlib \
		--with-config_file=/var/adm/aide/aide.conf

CONFIGURE_ENV+=	LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

MAN1=		aide.1
MAN5=		aide.conf.5

post-install:
	@${INSTALL_DATA} ${FILESDIR}/aide.conf.freebsd ${PREFIX}/etc/aide.conf.sample
	@${MKDIR} /var/adm/aide/databases
	@if [ ! -f /var/adm/aide/aide.conf ]; then \
		${CHOWN} root:wheel /var/adm/aide ; \
		${CHOWN} root:wheel /var/adm/aide/databases ; \
		${CHMOD} 0700 /var/adm/aide ; \
		${CHMOD} 0700 /var/adm/aide/databases ; \
	fi
	@${ECHO}
	@${CAT} ${PKGMESSAGE}
	@${ECHO}
.if defined(AIDE_FLOPPY)
	@disklabel -w -B /dev/rfd0c fd1440
	@newfs -u 0 -t 0 -i 196608 -m 0 -T minimum -o space /dev/rfd0c
	@mount /dev/fd0c /mnt
	@${CP} ${PREFIX}/bin/aide /mnt/aide
	@${CP} -p /var/adm/aide/aide.conf /mnt/aide.conf
	@${CP} < /var/adm/aide/databases/aide.db /mnt/aide.db
	@${CHMOD} 555 /mnt/aide
	@umount /mnt
	@${ECHO} Do not forget to remove and write-protect the floppy.
.endif

.include <bsd.port.mk>
