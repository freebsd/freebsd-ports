# New ports collection makefile for:   libqalculate
# Date created:        03 June 2004
# Whom:                Sergey Akifyev <asa@agava.com>
#
# $FreeBSD$
#

PORTNAME=	libqalculate
PORTVERSION=	0.9.3
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	qalculate

MAINTAINER=	asa@agava.com
COMMENT=	Very powerful GUI calculator for GNOME (backend library)

LIB_DEPENDS=	cln.4:${PORTSDIR}/math/cln

USE_GMAKE=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	intlhack gnomehack glib20 libxml2
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		does not build on FreeBSD 4.x
.endif

.include <bsd.port.post.mk>
