# New ports collection makefile for:	geomWatch
# Date created:				11 January 2010
# Whom:					Boris Kochergin <spawk@acm.poly.edu>
#
# $FreeBSD$
#

PORTNAME=	geomWatch
PORTVERSION=	1.2.1
CATEGORIES=	sysutils
MASTER_SITES=	http://isis.poly.edu/~bk/${PORTNAME}/ \
		http://bk.macroblock.net/${PORTNAME}/
EXTRACT_SUFX=	.tbz

MAINTAINER=	spawk@acm.poly.edu
COMMENT=	Watches for and e-mails admins about GEOM/ZFS state changes

LIB_DEPENDS=	esmtp.6:${PORTSDIR}/mail/libesmtp

SUB_FILES=	pkg-message

USE_RC_SUBR=	${PORTNAME}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700036
MAKE_ARGS+=	WITHOUT_ZFS=yes
.elif ${OSVERSION} < 702102 || \
	(${OSVERSION} >= 800000 && ${OSVERSION} < 800054)
MAKE_ARGS+=	WITH_ZFS=6
.endif

post-install:
	@if [ ! -f ${PREFIX}/etc/${PORTNAME}.conf ]; then \
		${CP} -p ${PREFIX}/etc/${PORTNAME}.conf.sample \
		${PREFIX}/etc/${PORTNAME}.conf ; \
	fi
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
