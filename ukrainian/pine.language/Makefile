# New ports collection makefile for:    uk-pine
# Whom:					Olexander Kunytsa <kunia@istc.kiev.ua>
# Date created:				17 April 2001
#
# $FreeBSD$
#

PORTNAME=	pine
PORTVERSION=	4.33
CATEGORIES=	ukrainian mail news
EXTRACT_ONLY=	# empty

MAINTAINER=	kunia@istc.kiev.ua
COMMENT=	Tune Pine for Ukrainian (KOI8-U) defaults

RUN_DEPENDS=	pine:${PORTSDIR}/mail/pine4

BROKEN=		Leaves behind config file on deinstall
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=2007-04-10

NO_WRKSUBDIR=	YES
NO_BUILD=	YES

SUB_FILES=	pkg-install pkg-deinstall
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall

do-fetch:
	${DO_NADA}

do-install:
	@${SETENV} ${SCRIPTS_ENV} PGPLIB="${PGPLIB}" PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} pkg-install

.include <bsd.port.mk>
