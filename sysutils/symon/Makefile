# New ports collection makefile for:	sysutils/symon
# Date created:				17.02.2005
# Whom:					Ulrich Spoerlein <q@uni.de>
#
# $FreeBSD$
#

PORTNAME=	symon
PORTVERSION=	2.70
CATEGORIES=	sysutils
MASTER_SITES=	http://www.xs4all.nl/~wpd/symon/philes/

MAINTAINER=	q@uni.de
COMMENT=	Performance and information monitoring tool

LIB_DEPENDS=	rrd.0:${PORTSDIR}/net/rrdtool

WRKSRC=		${WRKDIR}/${PORTNAME}
MAKE_ARGS+=	SYSCONFDIR=${LOCALBASE}/etc BINDIR=bin
PKGMESSAGE=	${WRKDIR}/.pkg-message

MAN8=	symon.8 symux.8

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
post-patch:
	@${ECHO} "" > ${WRKSRC}/platform/FreeBSD/Makefile.inc
.endif

post-build:
	@${SED} 's,%%LOCALBASE%%,${LOCALBASE},g' pkg-message > ${PKGMESSAGE}

pre-install:
	@${SH} ${PKGINSTALL} ${PORTNAME} PRE-INSTALL

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
