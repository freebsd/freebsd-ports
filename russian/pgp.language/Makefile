# New ports collection makefile for: pgp.language
# Date created:         4 May 1995
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	pgp
PORTVERSION=	2.6.3ia
CATEGORIES=	russian
MASTER_SITES=	ftp://ftp.kiarchive.ru/pub/unix/crypto/pgp/
DISTNAME=	pgp26ru

MAINTAINER=	ache@FreeBSD.org

RUN_DEPENDS+=	${LOCALBASE}/lib/pgp/config.txt:${PORTSDIR}/security/pgp

RESTRICTED=	"Crypto"

USE_ZIP=	YES
NO_WRKSUBDIR=	YES
NO_BUILD=	YES

PGPLIB=		${PREFIX}/lib/pgp
OBJS=		language.txt ru.hlp

do-install:
	[ -d ${PGPLIB} ] || ${MKDIR} ${PGPLIB}
	cd ${WRKSRC}; install -c -o bin -g bin -m 444 ${OBJS} ${PGPLIB}
	cd ${WRKSRC}; ${TR} -d '\015' < NOTES.ru > ${PGPLIB}/NOTES.ru
	cd ${PGPLIB}; ${GREP} -l -q '^Language.*=.*ru' config.txt || { \
		${CP} config.txt config.txt.bak; \
		${SED} 's/^Language.*=.*$$/Language = ru/' < config.txt.bak > config.txt; }
	-pgp > /dev/null  2>&1  # update .idx file

.include <bsd.port.mk>
