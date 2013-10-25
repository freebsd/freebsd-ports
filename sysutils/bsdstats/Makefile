# Created by: Marc G. Fournier <scrappy@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bsdstats
PORTVERSION=	5.5
PORTREVISION=	4
CATEGORIES=	sysutils
DISTFILES=

MAINTAINER=	bsdstats@nanoman.ca
COMMENT=	Monthly script for reporting anonymous statistics about your machine

NO_BUILD=	yes
USE_RC_SUBR=	bsdstats
SUB_FILES=	300.statistics pkg-message
SUB_LIST=	DIG=${DIG}

.include <bsd.port.options.mk>

.if ${OSVERSION} >= 1000500
DIG=		drill
.else
DIG=		dig
.endif

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/periodic/monthly
	${INSTALL_SCRIPT} ${WRKDIR}/300.statistics \
		${STAGEDIR}${PREFIX}/etc/periodic/monthly

.include <bsd.port.mk>
