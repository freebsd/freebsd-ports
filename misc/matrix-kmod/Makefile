# New ports collection makefile for:	strijar
# Date created:				22 Dec 2000
# Whom:					Oleg Belousov <strijar@urai.ru>
#
# $FreeBSD$
#

PORTNAME=	matrix
PORTVERSION=	1.2
CATEGORIES=	misc
MASTER_SITES=	http://www.belousov.com/download/
PKGNAMESUFFIX=	-kmod

MAINTAINER=     strijar@urai.ru

MAKE_ENV=	DESTDIR="${PREFIX}/lib/matrix"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400000
BROKEN=		"Need FreeBSD 4.0 or above"
.endif

pre-install:
	${MKDIR} ${PREFIX}/lib/matrix/modules

.include <bsd.port.post.mk>
