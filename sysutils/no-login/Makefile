# New ports collection makefile for:    nologin
# Date created:         15 Jul 1998
# Whom:                 Donald Burr <dburr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nologin
PORTVERSION= 	1.0
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.xmission.com/pub/users/s/softweyr/pub/
DISTFILES=	nologin.c nologin.8

MAINTAINER=	dburr@FreeBSD.org

DIST_SUBDIR=	nologin
NO_WRKSUBDIR=	YES
ALL_TARGET=	nologin

MAN8=		nologin.8

do-extract:
		@${MKDIR} ${WRKDIR}
		for FILE in ${DISTFILES} ; do ${CP} ${DISTDIR}/${DIST_SUBDIR}/$${FILE} ${WRKDIR}/$${FILE} ; done
		${CP} ${FILESDIR}/Makefile ${WRKDIR}

do-install:
		${INSTALL_PROGRAM} ${WRKDIR}/nologin ${PREFIX}/sbin
		${INSTALL_MAN} ${WRKDIR}/nologin.8 ${PREFIX}/man/man8

.include <bsd.port.mk>
