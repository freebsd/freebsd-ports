# New ports collection makefile for:	pfflowd
# Date created:		23 June 2003
# Whom:			Max Laier <max@love2party.net>
#
# $FreeBSD$
#

PORTNAME=	pftop
PORTVERSION=	0.4
CATEGORIES=	sysutils net
MASTER_SITES=	http://www.eee.metu.edu.tr/~canacar/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	max@love2party.net
COMMENT=	Utility for real-time display of statistics for pf

BUILD_DEPENDS=	${LOCALBASE}/include/pf/net/pfvar.h:${PORTSDIR}/security/pf
.if defined(WITH_ALTQ) && (${WITH_ALTQ} == "yes")
BUILD_DEPENDS+=${LOCALBASE}/include/pf/altq/altq.h:${PORTSDIR}/security/pf
.endif
RUN_DEPENDS=	${LOCALBASE}/modules/pf.ko:${PORTSDIR}/security/pf

MAN8=		pftop.8

MANCOMPRESSED=	no

CFLAGS+=	-I${LOCALBASE}/include/pf
MAKE_ARGS=	LOCALBASE="${PREFIX}" OSLEVEL=34
.if defined(WITH_ALTQ) && (${WITH_ALTQ} == "yes")
CFLAGS+=	-DHAVE_ALTQ=1
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		"Only for 5.0 and above"
.endif

PLIST_FILES=	sbin/pftop

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pftop ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/pftop.8 ${PREFIX}/man/man8

.include <bsd.port.post.mk>
