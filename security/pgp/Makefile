# New ports collection makefile for: pgp
# Date created:         8 Jul 1995
# Whom:                 ache
#
# $FreeBSD$
#

# Pick an initial default, else it doesn't get set in the INDEX.
CATEGORIES=	security
DISTNAME=	pgp262s

MAINTAINER=	ache@FreeBSD.org

# Need to define USA_RESIDENT to YES or NO
IS_INTERACTIVE=	YES
RESTRICTED=	"Crypto"
MAKEFILE=	makefile
ALL_TARGET=	freebsd-${MACHINE_ARCH} OS_CFLAGS="${CFLAGS}"
PGPLIB=		${PREFIX}/lib/pgp
MAN1=		pgp.1

do-install:
	cd ${WRKSRC}; install -c -o bin -g bin -m 555 pgp ${PREFIX}/bin
	cd ${WRKSRC}/../doc; \
		  install -c -o bin -g bin -m 444 pgp.1 ${PREFIX}/man/man1
	-${MKDIR} ${PGPLIB}
	${CHMOD} 555 ${PGPLIB}
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
	@${ECHO_MSG}
	@${ECHO_MSG} You must set variable USA_RESIDENT to YES, if you are USA resident
	@${ECHO_MSG} or to NO, if you aren\'t USA resident to build this package
	@${FALSE}
.elif defined(USA_RESIDENT)
.if ${USA_RESIDENT} == YES
PORTNAME=	pgp
PORTVERSION=	2.6.2
MASTER_SITES=	ftp://utopia.hacktic.nl/pub/replay/pub/pgp/unix/ \
		ftp://sable.ox.ac.uk/pub/crypto/pgp/unix/
DISTNAME=	pgp262s

WRKSRC=		${WRKDIR}/src
BUILD_DEPENDS+=	gmake:${PORTSDIR}/devel/gmake
LIB_DEPENDS+=	rsaref.2:${PORTSDIR}/security/rsaref
USE_ZIP=	yes
FILESDIR=	${.CURDIR}/files.usa
PATCHDIR=	${.CURDIR}/patches.usa

post-extract:
	cd ${WRKDIR}; $(EXTRACT_CMD) $(EXTRACT_BEFORE_ARGS) -aa $(DISTNAME)i \
		$(EXTRACT_AFTER_ARGS)
	cd ${WRKDIR}; ${RM} -f *.zip

.else
PORTNAME=	pgp
PORTVERSION=	2.6.3ia
MASTER_SITES=	ftp://ftp.ifi.uio.no/pub/pgp/2.x/src/ \
		ftp://ftp.kiarchive.ru/pub/unix/crypto/pgp/
DISTNAME=	pgp263is

WRKSRC=		${WRKDIR}/src
FILESDIR=	${.CURDIR}/files.non_usa
PATCHDIR=	${.CURDIR}/patches.non_usa

post-extract:
	cd ${WRKDIR}; $(TAR) -xf pgp263ii.tar; \
		${RM} -f pgp263ii.tar

.endif
.endif

.include <bsd.port.mk>
