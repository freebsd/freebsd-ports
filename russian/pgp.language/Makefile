# New ports collection makefile for: pgp.language
# Version required:     2.6
# Date created:         4 May 1995
# Whom:                 ache
#
# $Id: Makefile,v 1.5 1995/07/01 08:30:48 asami Exp $
#

DISTNAME=       pgp26ru
PKGNAME=	pgp-2.6.ru
CATEGORIES+=    utilities
MASTER_SITES=   ftp://ftp.kiae.su/unix/crypto/pgp/
EXTRACT_SUFX=   .zip

MAINTAINER=	ache@FreeBSD.ORG

EXEC_DEPENDS += unzip:${PORTSDIR}/archivers/unzip
EXEC_DEPENDS += pgp:${PORTSDIR}/utils/pgp
EXTRACT_CMD=    unzip
EXTRACT_ARGS=   -q
NO_WRKSUBDIR=   YES
NO_CONFIGURE=   YES
NO_PATCH=       YES
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
