# New ports collection makefile for: pgp
# Version required:     MIT 2.6.2 / International 2.6.3i
# PGP 2.6.3i homepage is http://www.ifi.uio.no/~staalesc/PGP/home.html
# Date created:         8 Jul 1995
# Whom:                 ache
#
# $Id: Makefile,v 1.5 1995/09/15 21:10:06 ache Exp $
#

CATEGORIES+=	security

MAINTAINER=	ache@FreeBSD.ORG
WRKSRC=         ${WRKDIR}/src
NO_PACKAGE=     YES
MAKEFILE=       makefile
ALL_TARGET=     freebsd
PGPLIB=         ${PREFIX}/lib/pgp
BUILD_DEPENDS=  unzip:${PORTSDIR}/archivers/unzip
# Need to define USA_RESIDENT to YES or NO
IS_INTERACTIVE=	YES

do-install:
	cd ${WRKSRC}; install -c -o bin -g bin -m 555 pgp ${PREFIX}/bin
	cd ${WRKDIR}/doc; \
		  install -c -o bin -g bin -m 444 pgp.1 ${PREFIX}/man/man1
	-mkdir -p ${PGPLIB}
	chown bin.bin ${PGPLIB}
	chmod 555 ${PGPLIB}
	cd ${WRKDIR}; \
	    install -c -o bin -g bin -m 444 pgp.hlp \
			      doc/pgpdoc1.txt doc/pgpdoc2.txt ${PGPLIB}; \
	    [ -f ${PGPLIB}/language.txt ] || \
		      install -c -o bin -g bin -m 444 language.txt ${PGPLIB}; \
	    [ -f ${PGPLIB}/config.txt ] || \
		      install -c -o bin -g bin -m 444 config.txt ${PGPLIB}
	-${PREFIX}/bin/pgp > /dev/null  2>&1  # update .idx file

.if !defined(USA_RESIDENT) || ${USA_RESIDENT} != YES && ${USA_RESIDENT} != NO
exec_depends:
	@echo
	@echo You must set variable USA_RESIDENT to YES, if you are USA resident
	@echo or to NO, if you aren\'t USA resident to build this package
	@false
.elif defined(USA_RESIDENT)
.if ${USA_RESIDENT} == YES
DISTNAME=       pgp262s
PKGNAME=	pgp-2.6.2
MASTER_SITES=   ftp://sable.ox.ac.uk/pub/crypto/pgp/unix/
EXTRACT_SUFX=   .zip
BUILD_DEPENDS+= gmake:${PORTSDIR}/devel/gmake
EXTRACT_CMD=    unzip
EXTRACT_ARGS=   -q
FILESDIR=       ${.CURDIR}/files.usa
PATCHDIR=       ${.CURDIR}/patches.usa

post-extract:
	cd ${WRKDIR}; $(EXTRACT_CMD) $(EXTRACT_ARGS) -aa $(DISTNAME)i
	cd ${WRKDIR}; $(EXTRACT_CMD) $(EXTRACT_ARGS) -aa rsaref
	cd ${WRKDIR}; rm -f *.zip

pre-build:
	cd ${WRKDIR}/rsaref/install/unix; ${GMAKE}
.else
DISTNAME=       pgp263i-dev
PKGNAME=        pgp-2.6.3i
MASTER_SITES=   ftp://ftp.ifi.uio.no/pub/pgp/incoming/ \
		ftp://ftp.kiae.su/unix/crypto/pgp/
EXTRACT_SUFX=   .zip
EXTRACT_CMD=    unzip
EXTRACT_ARGS=   -qa
FILESDIR=       ${.CURDIR}/files.non_usa

pre-configure:
	cd ${WRKSRC}; cp makefile.unx makefile

.endif
.endif

.include <bsd.port.mk>
