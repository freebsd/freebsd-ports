# New ports collection makefile for: pgp
# Version required:     MIT 2.6.2 / International 2.6.3ia
# International PGP homepage is http://www.ifi.uio.no/pgp/
#
# Date created:         8 Jul 1995
# Whom:                 ache
#
# $Id: Makefile,v 1.21 1998/09/25 10:20:21 asami Exp $
#

# Pick an initial default, else it doesn't get set in the INDEX.
DISTNAME=	pgp262s
CATEGORIES=	security

MAINTAINER=	ache@FreeBSD.ORG

# Need to define USA_RESIDENT to YES or NO
IS_INTERACTIVE=	YES
RESTRICTED=     "Crypto"
MAKEFILE=       makefile
ALL_TARGET=     freebsd
PGPLIB=         ${PREFIX}/lib/pgp
MAN1=		pgp.1

do-install:
	cd ${WRKSRC}; install -c -o bin -g bin -m 555 pgp ${PREFIX}/bin
	cd ${WRKSRC}/../doc; \
		  install -c -o bin -g bin -m 444 pgp.1 ${PREFIX}/man/man1
	-mkdir -p ${PGPLIB}
	chown bin.bin ${PGPLIB}
	chmod 555 ${PGPLIB}
	cd ${WRKSRC}/..; \
	    install -c -o bin -g bin -m 444 pgp.hlp \
			      doc/pgpdoc1.txt doc/pgpdoc2.txt ${PGPLIB}; \
	    [ -f ${PGPLIB}/language.txt ] || \
		      install -c -o bin -g bin -m 444 language.txt ${PGPLIB}; \
	    [ -f ${PGPLIB}/config.txt ] || \
		      install -c -o bin -g bin -m 444 config.txt ${PGPLIB}
	-${PREFIX}/bin/pgp > /dev/null  2>&1  # update .idx file

.if !defined(USA_RESIDENT) || ${USA_RESIDENT} != YES && ${USA_RESIDENT} != NO
pre-fetch:
	@echo
	@echo You must set variable USA_RESIDENT to YES, if you are USA resident
	@echo or to NO, if you aren\'t USA resident to build this package
	@false
.elif defined(USA_RESIDENT)
.if ${USA_RESIDENT} == YES
DISTNAME=       pgp262s
PKGNAME=	pgp-2.6.2
MASTER_SITES=   ftp://utopia.hacktic.nl/pub/replay/pub/pgp/unix/ \
		ftp://sable.ox.ac.uk/pub/crypto/pgp/unix/
EXTRACT_SUFX=   .zip
WRKSRC=         ${WRKDIR}/src
BUILD_DEPENDS+= gmake:${PORTSDIR}/devel/gmake
BUILD_DEPENDS+= unzip:${PORTSDIR}/archivers/unzip
LIB_DEPENDS+=   rsaref.2:${PORTSDIR}/security/rsaref
EXTRACT_CMD=    unzip
EXTRACT_BEFORE_ARGS=	-q
EXTRACT_AFTER_ARGS=	# empty
FILESDIR=       ${.CURDIR}/files.usa
PATCHDIR=       ${.CURDIR}/patches.usa

post-extract:
	cd ${WRKDIR}; $(EXTRACT_CMD) $(EXTRACT_BEFORE_ARGS) -aa $(DISTNAME)i \
		$(EXTRACT_AFTER_ARGS)
	cd ${WRKDIR}; rm -f *.zip

.else
DISTNAME=       pgp263is
PKGNAME=        pgp-2.6.3ia
MASTER_SITES=   ftp://ftp.ifi.uio.no/pub/pgp/2.x/src/ \
		ftp://ftp.kiarchive.ru/pub/unix/crypto/pgp/
WRKSRC=         ${WRKDIR}/src
FILESDIR=       ${.CURDIR}/files.non_usa
PATCHDIR=       ${.CURDIR}/patches.non_usa

post-extract:
	cd ${WRKDIR}; $(EXTRACT_CMD) -xf pgp263ii.tar; \
		rm -f pgp263ii.tar

.endif
.endif

.include <bsd.port.mk>
