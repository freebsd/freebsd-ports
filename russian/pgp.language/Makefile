# New ports collection makefile for: pgp.language
# Version required:     2.6.3ia
# Date created:         4 May 1995
# Whom:                 ache
#
# $Id: Makefile,v 1.20 1998/10/19 20:00:35 ache Exp $
#

DISTNAME=       pgp26ru
PKGNAME=        ru-pgp-2.6.3ia
CATEGORIES=     russian
MASTER_SITES=   ftp://ftp.kiarchive.ru/pub/unix/crypto/pgp/
EXTRACT_SUFX=   .zip

MAINTAINER=	ache@FreeBSD.ORG

RESTRICTED=	"Crypto"

BUILD_DEPENDS += unzip:${PORTSDIR}/archivers/unzip
RUN_DEPENDS += ${PREFIX}/lib/pgp/config.txt:${PORTSDIR}/security/pgp

EXTRACT_CMD=    unzip
EXTRACT_BEFORE_ARGS=	-q
EXTRACT_AFTER_ARGS=	# empty
NO_WRKSUBDIR=   YES
NO_BUILD=       YES

PGPLIB=         ${PREFIX}/lib/pgp
OBJS=           language.txt ru.hlp

do-install:
	[ -d ${PGPLIB} ] || mkdir -p ${PGPLIB}
	cd ${WRKSRC}; install -c -o bin -g bin -m 444 ${OBJS} ${PGPLIB}
	cd ${WRKSRC}; tr -d '\015' < NOTES.ru > ${PGPLIB}/NOTES.ru
	cd ${PGPLIB}; grep -l -q '^Language.*=.*ru' config.txt || { \
		cp config.txt config.txt.bak; \
		sed 's/^Language.*=.*$$/Language = ru/' < config.txt.bak > config.txt; }
	-pgp > /dev/null  2>&1  # update .idx file

.include <bsd.port.mk>
