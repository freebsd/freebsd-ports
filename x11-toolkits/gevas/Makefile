# ports collection makefile for:	gevas
# Date created:				19 March 2001
# Whom:					Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	gevas
PORTVERSION=	0.0.3
CATEGORIES=	x11-toolkits graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	enlightenment

MAINTAINER=	ishmael27x@yahoo.com

LIB_DEPENDS=	evas.6:${PORTSDIR}/graphics/evas

USE_GTK=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

post-install:
	@strip ${PREFIX}/lib/libgevas.so.0

.include <bsd.port.mk>
