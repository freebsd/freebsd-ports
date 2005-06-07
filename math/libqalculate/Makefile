# New ports collection makefile for:   libqalculate
# Date created:        03 June 2004
# Whom:                Sergey Akifyev <asa@agava.com>
#
# $FreeBSD$
#

PORTNAME=	libqalculate
PORTVERSION=	0.8.0
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	qalculate

MAINTAINER=	asa@agava.com
COMMENT=	Very powerful GUI calculator for GNOME (backend library)

LIB_DEPENDS=	cln.3:${PORTSDIR}/math/cln

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_INC_LIBTOOL_VER=15
USE_GNOME=	intlhack lthack pkgconfig gnomehack glib20 libxml2
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		"does not configure"
.endif

.include <bsd.port.post.mk>
