# New ports collection makefile for:    ru-pine
# Whom:                 ache
# Date created:		1996/12/03
#
# $FreeBSD$
#

PORTNAME=	pine
PORTVERSION=	4.21
CATEGORIES=	russian mail
EXTRACT_ONLY=	# empty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tune Pine for Russian (KOI8-R) defaults

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
