# New ports collection makefile for: pgpin
# Date created:         23 Mar 2001
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	pgpin
PORTVERSION=	010323
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dinoex
DISTNAME=	pgp263in${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	PGP International version - improved for use in IN-CA

WRKSRC=		${WRKDIR}/pgp263in/src

MAKEFILE=	makefile
ALL_TARGET=	freebsd-${ARCH} OS_CFLAGS="${CFLAGS}"
PGPLIB=		${PREFIX}/lib/pgpin
MAN1=		pgpin.1

do-install:
	cd ${WRKSRC}; ${INSTALL_PROGRAM} -c -o bin -g bin -m 555 \
		pgp ${PREFIX}/bin/pgpin
	cd ${WRKSRC}/../doc; \
		${INSTALL_MAN} -c -o bin -g bin -m 444 \
		pgp.1 ${PREFIX}/man/man1/pgpin.1
	-${MKDIR} ${PGPLIB}
	${CHMOD} 555 ${PGPLIB}
	${INSTALL_DATA} -c -o bin -g bin -m 444 \
			${FILESDIR}/CHANGES ${PGPLIB}
	cd ${WRKSRC}/..; \
		${INSTALL_DATA} -c -o bin -g bin -m 444 \
			pgp.hlp doc/pgpdoc1.txt doc/pgpdoc2.txt ${PGPLIB}; \
		${INSTALL_DATA} -c -o bin -g bin -m 444 \
			language.txt ${PGPLIB}/language.txt-dist; \
		[ -f ${PGPLIB}/language.txt ] || \
		${INSTALL_DATA} -c -o bin -g bin -m 444 \
			language.txt ${PGPLIB}; \
		${INSTALL_DATA} -c -o bin -g bin -m 444 \
			config.txt ${PGPLIB}/config.txt-dist; \
		[ -f ${PGPLIB}/config.txt ] || \
		${INSTALL_DATA} -c -o bin -g bin -m 444 \
			config.txt ${PGPLIB}
	-${PREFIX}/bin/pgpin > /dev/null  2>&1  # update .idx file

.include <bsd.port.mk>
