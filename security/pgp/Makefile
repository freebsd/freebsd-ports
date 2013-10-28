# Created by: ache
# $FreeBSD$

PORTNAME=	pgp
PORTVERSION=	2.6.3i
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	PACKETSTORM/crypt/pgp/V5.0
DISTNAME=	pgp263is

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PGP International version - Public-Key encryption for the masses

ONLY_FOR_ARCHS=	i386 alpha amd64 sparc64

WRKSRC=		${WRKDIR}/src
MAKEFILE=	makefile
ALL_TARGET=	freebsd-${ARCH:S/x86_64/amd64/}
MAKE_ENV=	OS_CFLAGS="${CFLAGS}"
PGPLIB=		${STAGEDIR}${PREFIX}/share/pgp

post-extract:
	cd ${WRKDIR}; ${TAR} -xf pgp263ii.tar; \
		${RM} -f pgp263ii.tar

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pgp ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/../doc/pgp.1 ${STAGEDIR}${PREFIX}/man/man1/
	-${MKDIR} ${PGPLIB}
	cd ${WRKSRC}/.. && \
		${INSTALL_DATA} pgp.hlp doc/pgpdoc1.txt doc/pgpdoc2.txt ${PGPLIB}/
	${INSTALL_DATA} ${WRKSRC}/../language.txt ${PGPLIB}/language.txt-dist
	${INSTALL_DATA} ${WRKSRC}/../config.txt ${PGPLIB}/config.txt-dist

post-install:
	${INSTALL_MAN} ${STAGEDIR}${PREFIX}/man/man1/pgp.1 ${STAGEDIR}${PREFIX}/man/man1/pgp2.1

.include <bsd.port.mk>
