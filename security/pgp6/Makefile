# New ports collection makefile for:	pgp6
# Date created:				25 Jan 2000
# Whom:					mike@fate.com
#
# $FreeBSD$
#

PORTNAME=	pgp
PORTVERSION=	6.5.8
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.no.pgpi.org/pub/pgp/${PORTVERSION:R}/${PORTVERSION}/ \
		ftp://ftp.fi.pgpi.org/pub/pgp/${PORTVERSION:R}/${PORTVERSION}/ \
		ftp://ftp.se.pgpi.org/pub/pgp/${PORTVERSION:R}/${PORTVERSION}/ \
		ftp://ftp.de.pgpi.org/pub/pgp/${PORTVERSION:R}/${PORTVERSION}/ \
		ftp://ftp.dk.pgpi.org/pub/pgp/${PORTVERSION:R}/${PORTVERSION}/ \
		ftp://ftp.nl.pgpi.org/pub/pgp/${PORTVERSION:R}/${PORTVERSION}/ \
		ftp://ftp.ch.pgpi.org/pub/pgp/${PORTVERSION:R}/${PORTVERSION}/ \
		ftp://ftp.jp.pgpi.org/pub/pgp/${PORTVERSION:R}/${PORTVERSION}/ \
		ftp://ftp.ru.pgpi.org/pub/pgp/${PORTVERSION:R}/${PORTVERSION}/
DISTNAME=	pgpsrc658unix

MAINTAINER=	rabbi@abditum.com
COMMENT=	Public-Key encryption for the masses

WRKSRC=		${WRKDIR}/pgpsrc
USE_GMAKE=	yes

MAN1=		pgp.1
PLIST_FILES=	bin/pgp

LATEST_LINK=	pgp6

.include <bsd.port.pre.mk>

# the distfile is actually a tar of three compressed tars and their
# signatures
post-extract:
	cd ${WRKDIR} && \
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTNAME}.tar.gz \
		${EXTRACT_AFTER_ARGS} && \
	${RM} ${DISTNAME}.tar.gz ${DISTNAME}.tar.gz.sig
.if !defined(EXTRACT_PRESERVE_OWNERSHIP)
	if [ `id -u` = 0 ]; then \
		${CHMOD} -R ug-s ${WRKDIR}; \
		${CHOWN} -R 0:0 ${WRKDIR}; \
	fi
.endif
	${CP} ${FILESDIR}/build.Makefile ${WRKSRC}/Makefile

do-install:
	cd ${WRKSRC}/clients/pgp/cmdline ; ${GMAKE} install ; \
	${INSTALL_MAN} packaging/pgp-6.0/man/man1/pgp.1 ${PREFIX}/man/man1

.include <bsd.port.post.mk>
