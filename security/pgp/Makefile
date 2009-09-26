# New ports collection makefile for: pgp
# Date created:         8 Jul 1995
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	pgp
PORTVERSION=	2.6.3i
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.ifi.uio.no/pub/pgp/2.x/src/ \
		ftp://ftp.kiarchive.ru/pub/unix/crypto/pgp/
DISTNAME=	pgp263is

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PGP International version - Public-Key encryption for the masses

WRKSRC=		${WRKDIR}/src

MAKEFILE=	makefile
ALL_TARGET=	freebsd-${ARCH}
MAKE_ENV=	OS_CFLAGS="${CFLAGS}"
PGPLIB=		${PREFIX}/share/pgp
MAN1=		pgp.1 pgp2.1
ONLY_FOR_ARCHS=	i386 alpha amd64 sparc64

do-install:
	cd ${WRKSRC}; ${INSTALL_PROGRAM} -c -o bin -g bin -m 555 pgp ${PREFIX}/bin
	cd ${WRKSRC}/../doc; \
		  ${INSTALL_MAN} -c -o bin -g bin -m 444 pgp.1 ${PREFIX}/man/man1
	-${MKDIR} ${PGPLIB}
	${CHMOD} 555 ${PGPLIB}
	cd ${WRKSRC}/..; \
	    ${INSTALL_DATA} -c -o bin -g bin -m 444 pgp.hlp \
			      doc/pgpdoc1.txt doc/pgpdoc2.txt ${PGPLIB}; \
	    ${INSTALL_DATA} -c -o bin -g bin -m 444 language.txt ${PGPLIB}/language.txt-dist; \
	    [ -f ${PGPLIB}/language.txt ] || \
		      ${INSTALL_DATA} -c -o bin -g bin -m 444 language.txt ${PGPLIB}; \
	    ${INSTALL_DATA} -c -o bin -g bin -m 444 config.txt ${PGPLIB}/config.txt-dist; \
	    [ -f ${PGPLIB}/config.txt ] || \
		      ${INSTALL_DATA} -c -o bin -g bin -m 444 config.txt ${PGPLIB}
	-${PREFIX}/bin/pgp > /dev/null  2>&1  # update .idx file

post-extract:
	cd ${WRKDIR}; ${TAR} -xf pgp263ii.tar; \
		${RM} -f pgp263ii.tar

post-install:
	@${CP} ${PREFIX}/man/man1/pgp.1 ${PREFIX}/man/man1/pgp2.1

.include <bsd.port.mk>
