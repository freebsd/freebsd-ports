# New ports collection makefile for:	pgp6
# Date created:				25 Jan 2000
# Whom:					mike@fate.com
#
# $FreeBSD$
#

PORTNAME=	pgp
PORTVERSION=	6.5.1i
CATEGORIES=	security
MASTER_SITES=   ftp://ftp.no.pgpi.org/pub/pgp/6.5/6.5.1i/unix/ \
		ftp://ftp.fi.pgpi.org/pub/pgp/6.5/6.5.1i/unix/ \
		ftp://ftp.se.pgpi.org/pub/pgp/6.5/6.5.1i/unix/ \
		ftp://ftp.de.pgpi.org/pub/pgp/6.5/6.5.1i/unix/ \
		ftp://ftp.dk.pgpi.org/pub/pgp/6.5/6.5.1i/unix/ \
		ftp://ftp.nl.pgpi.org/pub/pgp/6.5/6.5.1i/unix/ \
		ftp://ftp.ch.pgpi.org/pub/pgp/6.5/6.5.1i/unix/ \
		ftp://ftp.ru.pgpi.org/pub/pgp/6.5/6.5.1i/unix/
EXTRACT_SUFX=   -beta2.tar.gz

MAINTAINER=	mike@fate.com

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_GMAKE=      YES

RESTRICTED=     "Crypto"

MAN1=		pgp.1

do-install:
	cd ${WRKSRC}/clients/pgp/cmdline ; ${GMAKE} install

post-extract:
	${CP} ${FILESDIR}/build.Makefile ${WRKDIR}/${PKGNAME}/Makefile

.include <bsd.port.mk>
