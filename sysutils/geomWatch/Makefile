# New ports collection makefile for:	geomWatch
# Date created:				11 January 2010
# Whom:					Boris Kochergin <spawk@acm.poly.edu>
#
# $FreeBSD$
#

PORTNAME=	geomWatch
PORTVERSION=	1.2.0
CATEGORIES=	sysutils
MASTER_SITES=	http://isis.poly.edu/~bk/${PORTNAME}/ \
		http://bk.macroblock.net/${PORTNAME}/
EXTRACT_SUFX=	.tbz

MAINTAINER=	spawk@acm.poly.edu
COMMENT=	Watches for and e-mails admins about GEOM/ZFS state changes

LIB_DEPENDS=	esmtp.6:${PORTSDIR}/mail/libesmtp

PLIST_FILES=	sbin/${PORTNAME} \
		etc/${PORTNAME}.conf.sample

SUB_FILES=	pkg-message

USE_RC_SUBR=	${PORTNAME}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
