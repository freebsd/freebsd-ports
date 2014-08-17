# Created by: Boris Kochergin <spawk@acm.poly.edu>
# $FreeBSD$

PORTNAME=	geomWatch
PORTVERSION=	1.3.0
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://isis.poly.edu/~bk/${PORTNAME}/ \
		http://bk.macroblock.net/${PORTNAME}/
EXTRACT_SUFX=	.tbz

MAINTAINER=	spawk@acm.poly.edu
COMMENT=	Watches for and e-mails admins about GEOM/ZFS state changes

LIB_DEPENDS=	libesmtp.so:${PORTSDIR}/mail/libesmtp

SUB_FILES=	pkg-message

USE_RC_SUBR=	${PORTNAME}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700036
MAKE_ARGS+=	WITHOUT_ZFS=yes
.elif ${OSVERSION} < 702102 || \
	(${OSVERSION} >= 800000 && ${OSVERSION} < 800054)
MAKE_ARGS+=	WITH_ZFS=6
.elif (${OSVERSION} >= 702102 && ${OSVERSION} < 800000) || \
	(${OSVERSION} >= 800054 && ${OSVERSION} < 802506) || \
	(${OSVERSION} >= 900000 && ${OSVERSION} < 900033)
MAKE_ARGS+=	WITH_ZFS=13
.else
MAKE_ARGS+=	WITH_ZFS=28
.endif

.include <bsd.port.post.mk>
