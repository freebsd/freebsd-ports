# New ports collection makefile for:	aide
# Date created:				Tue Jan  4 11:45:29 PST 2000
# Whom:					Cy Schubert (Cy.Schubert@uumail.gov.bc.ca)
#
# $FreeBSD$
#

PORTNAME=	aide
PORTVERSION=	0.13.1
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	SF \
		http://www.cs.tut.fi/~rammer/


MAINTAINER=	cy@FreeBSD.org
COMMENT=	A replacement and extension for Tripwire

LIB_DEPENDS=	mhash.2:${PORTSDIR}/security/mhash

.include <bsd.port.pre.mk>

USE_GMAKE=	yes
USE_BISON=	build
USE_AUTOTOOLS=	autoconf:262
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-mhash \
		--with-zlib \
		--mandir=${MANPREFIX}/man \
		--with-config_file=${PREFIX}/etc/aide.conf

CONFIGURE_ENV+=	CFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

MAN1=		aide.1
MAN5=		aide.conf.5

SUB_FILES=	pkg-message

post-install:
	@${INSTALL_DATA} ${FILESDIR}/aide.conf.freebsd ${PREFIX}/etc/aide.conf.sample
	@if [ ! -f ${PREFIX}/etc/aide.conf ]; then \
		${INSTALL_DATA} ${FILESDIR}/aide.conf.freebsd ${PREFIX}/etc/aide.conf ; \
	fi
	@if [ ! -d /var/db/aide/databases ]; then \
		${MKDIR} /var/db/aide/databases; \
		${CHOWN} root:wheel /var/db/aide ; \
		${CHOWN} root:wheel /var/db/aide/databases ; \
		${CHMOD} 0700 /var/db/aide ; \
		${CHMOD} 0700 /var/db/aide/databases ; \
	fi
	@${ECHO}
	@${CAT} ${PKGMESSAGE}
	@${ECHO}
.if defined(AIDE_FLOPPY)
	@disklabel -w -B /dev/rfd0c fd1440
	@newfs -u 0 -t 0 -i 196608 -m 0 -T minimum -o space /dev/rfd0c
	@mount /dev/fd0c /mnt
	@${CP} ${PREFIX}/bin/aide /mnt/aide
	@${CP} -p /var/db/aide/aide.conf /mnt/aide.conf
	@${CP} < /var/db/aide/databases/aide.db /mnt/aide.db
	@${CHMOD} 555 /mnt/aide
	@umount /mnt
	@${ECHO} Do not forget to remove and write-protect the floppy.
.endif

.include <bsd.port.post.mk>
