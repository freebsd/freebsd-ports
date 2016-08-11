# $FreeBSD$

PORTNAME=	pgpin
PORTVERSION=	010323
CATEGORIES=	security
MASTER_SITES=	LOCAL/dinoex
DISTNAME=	pgp263in${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	PGP International version - improved for use in IN-CA

BROKEN_powerpc64=	Does not build

USES=		tar:tgz
WRKSRC=		${WRKDIR}/pgp263in/src
MAKEFILE=	makefile
ALL_TARGET=	freebsd-${ARCH} OS_CFLAGS="${CFLAGS}"
PGPLIB=		${STAGEDIR}${PREFIX}/lib/pgpin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pgp ${STAGEDIR}${PREFIX}/bin/pgpin
	${INSTALL_MAN} ${WRKSRC}/../doc/pgp.1 ${STAGEDIR}${PREFIX}/man/man1/pgpin.1
	-${MKDIR} ${PGPLIB}
	${INSTALL_DATA} ${FILESDIR}/CHANGES ${PGPLIB}/
	cd ${WRKSRC}/.. && \
		${INSTALL_DATA} pgp.hlp doc/pgpdoc1.txt doc/pgpdoc2.txt ${PGPLIB}/
	${INSTALL_DATA} ${WRKSRC}/../language.txt ${PGPLIB}/language.txt.sample
	${INSTALL_DATA} ${WRKSRC}/../config.txt ${PGPLIB}/config.txt.sample

.include <bsd.port.mk>
