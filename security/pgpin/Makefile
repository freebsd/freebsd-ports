# $FreeBSD$

PORTNAME=	pgpin
PORTVERSION=	010323
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	LOCAL/dinoex \
		ftp://ftp.iks-jena.de/pub/mitarb/lutz/crypt/software/pgp/pgp263in/
DISTNAME=	pgp263in${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	PGP International version - improved for use in IN-CA

LICENSE=	MIT

PORTSCOUT=	ignore:1

BROKEN_mips64=		Does not build
BROKEN_powerpc64=	Does not build

USES=		tar:tgz
WRKSRC=		${WRKDIR}/pgp263in/src
MAKEFILE=	makefile
ALL_TARGET=	freebsd-${ARCH} OS_CFLAGS="${CFLAGS}"
PGPLIB=		${STAGEDIR}${PREFIX}/lib/pgpin

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pgp ${STAGEDIR}${PREFIX}/bin/pgpin
	${INSTALL_MAN} ${WRKSRC}/../doc/pgp.1 ${STAGEDIR}${PREFIX}/man/man1/pgpin.1
	${MKDIR} ${PGPLIB}
	${INSTALL_DATA} ${WRKSRC}/../pgp.hlp ${PGPLIB}/
	${INSTALL_DATA} ${WRKSRC}/../language.txt ${PGPLIB}/language.txt.sample
	${INSTALL_DATA} ${WRKSRC}/../config.txt ${PGPLIB}/config.txt.sample
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${FILESDIR}/CHANGES ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/../doc/pgpdoc1.txt \
		${WRKSRC}/../doc/pgpdoc2.txt ${STAGEDIR}${DOCSDIR}/
.endif

.include <bsd.port.mk>
