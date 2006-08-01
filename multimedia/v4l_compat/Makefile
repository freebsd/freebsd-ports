# New ports collection makefile for:	v4l_compat
# Date created:				Aug 1 2006
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	v4l_compat
PORTVERSION=	1.0.${DUMMYDATE}
CATEGORIES=	multimedia
MASTER_SITES=	# none
DISTFILES=	# none
DUMMYDATE=	20060801

MAINTAINER=	flz@FreeBSD.org
COMMENT=	Video4Linux compatibility header

NO_BUILD=	yes

do-install:
	${MKDIR} ${PREFIX}/include/linux/
	${INSTALL_DATA} ${FILESDIR}/videodev.h ${PREFIX}/include/linux/

.include <bsd.port.mk>
