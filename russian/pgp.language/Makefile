# New ports collection makefile for: pgp.language
# Date created:         4 May 1995
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	pgp
PORTVERSION=	2.6.3ia
PORTREVISION=	3
CATEGORIES=	russian
MASTER_SITES=	ftp://ftp.kiarchive.ru/pub/unix/crypto/pgp/
DISTNAME=	pgp26ru

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Russian language module for PGP

RUN_DEPENDS=	${LOCALBASE}/share/pgp/config.txt:${PORTSDIR}/security/pgp

USE_ZIP=	YES
NO_WRKSUBDIR=	YES
NO_BUILD=	YES

SUB_FILES=	pkg-install pkg-deinstall
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall

PGPLIB=		${PREFIX}/share/pgp
OBJS=		language.txt ru.hlp

do-install:
	[ -d ${PGPLIB} ] || ${MKDIR} ${PGPLIB}
	cd ${WRKSRC}; \
		if [ ! -f ${PGPLIB}/language.txt-ru ]; then \
			${CP} ${PGPLIB}/language.txt ${PGPLIB}/language.txt-ru; \
		fi; \
		${INSTALL_DATA} ${OBJS} ${PGPLIB}; \
		${TR} -d '\015' < NOTES.ru > ${PGPLIB}/NOTES.ru

post-install:
	@${SETENV} ${SCRIPTS_ENV} PGPLIB="${PGPLIB}" PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} pkg-install

.include <bsd.port.mk>
