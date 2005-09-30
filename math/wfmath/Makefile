# New ports collection makefile for:   wfmath
# Date created:        3 February 2005
# Whom:                Janni
#
# $FreeBSD$
#

PORTNAME=	wfmath
PORTVERSION=	0.3.4
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	worldforge

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	Worldforge math library

USE_GMAKE=	yes
USE_GNOME=	pkgconfig gnomehack
INSTALLS_SHLIB=	yes
USE_LIBTOOL_VER=15

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		Does not compile
.endif

.include <bsd.port.post.mk>
