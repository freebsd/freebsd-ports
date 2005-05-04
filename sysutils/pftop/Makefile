# New ports collection makefile for:	pfflowd
# Date created:		23 June 2003
# Whom:			Max Laier <max@love2party.net>
#
# $FreeBSD$
#

PORTNAME=	pftop
PORTVERSION=	0.4
PORTREVISION=	2
CATEGORIES=	sysutils net
MASTER_SITES=	http://www.eee.metu.edu.tr/~canacar/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	mlaier@freebsd.org
COMMENT=	Utility for real-time display of statistics for pf

MAN8=		pftop.8

MANCOMPRESSED=	no

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		Only for 5.0 and above
.endif

.if ${OSVERSION} < 502116
MAKE_ARGS=	LOCALBASE="${PREFIX}" OSLEVEL=34
.if defined(WITH_ALTQ) && (${WITH_ALTQ} == "yes")
CFLAGS+=	-DHAVE_ALTQ=1
.endif
.elif ${OSVERSION} < 600025
MAKE_ARGS=	LOCALBASE="${PREFIX}" OSLEVEL=35
CFLAGS+=	-DHAVE_ALTQ=1 -DHAVE_RULE_ANCHOR=1
.else
MAKE_ARGS=	LOCALBASE="${PREFIX}" OSLEVEL=37
CFLAGS+=	-DHAVE_ALTQ=1
.endif

.if ${OSVERSION} < 502106
BUILD_DEPENDS=	${LOCALBASE}/include/pf/net/pfvar.h:${PORTSDIR}/security/pf
.if defined(WITH_ALTQ) && (${WITH_ALTQ} == "yes")
BUILD_DEPENDS+=${LOCALBASE}/include/pf/altq/altq.h:${PORTSDIR}/security/pf
.endif
RUN_DEPENDS=	${LOCALBASE}/modules/pf.ko:${PORTSDIR}/security/pf

CFLAGS+=	-I${LOCALBASE}/include/pf
.endif

PLIST_FILES=	sbin/pftop

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pftop ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/pftop.8 ${PREFIX}/man/man8

.include <bsd.port.post.mk>
