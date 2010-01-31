# New ports collection makefile for:	geomWatch
# Date created:				11 January 2010
# Whom:					Boris Kochergin <spawk@acm.poly.edu>
#
# $FreeBSD$
#

PORTNAME=	geomWatch
PORTVERSION=	1.1.1
CATEGORIES=	sysutils
MASTER_SITES=	http://isis.poly.edu/~bk/geomWatch/ \
		http://bk.macroblock.net/geomWatch/
EXTRACT_SUFX=	.tbz

MAINTAINER=	spawk@acm.poly.edu
COMMENT=	Watches for and e-mails admins about GEOM state changes

LIB_DEPENDS=	esmtp.6:${PORTSDIR}/mail/libesmtp

PLIST_FILES=	sbin/geomWatch \
				etc/rc.d/geomWatch \
		etc/geomWatch.conf.sample

SUB_FILES=	pkg-message geomWatch

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/geomWatch ${PREFIX}/etc/rc.d/geomWatch
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
