# Created by: Marc G. Fournier <scrappy@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bsdstats
PORTVERSION=	5.5
PORTREVISION=	5
CATEGORIES=	sysutils
DISTFILES=

MAINTAINER=	bsdstats@nanoman.ca
COMMENT=	Monthly script for reporting anonymous statistics about your machine

NO_BUILD=	yes
USE_RC_SUBR=	bsdstats
SUB_FILES=	300.statistics pkg-message
SUB_LIST+=	DIG=${DIG}

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 1000500
DIG=		drill
.else
DIG=		dig
.endif

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/periodic/monthly
	${INSTALL_SCRIPT} ${WRKDIR}/300.statistics \
		${STAGEDIR}${PREFIX}/etc/periodic/monthly

post-install:
.if ! defined(BATCH) && ! defined(PACKAGE_BUILDING)
	@PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif

.include <bsd.port.post.mk>
