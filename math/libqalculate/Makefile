# New ports collection makefile for:   libqalculate
# Date created:        03 June 2004
# Whom:                Sergey Akifyev <asa@agava.com>
#
# $FreeBSD$
#

PORTNAME=	libqalculate
PORTVERSION=	0.9.6
CATEGORIES=	math
MASTER_SITES=	SF/qalculate

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A a multi-purpose desktop calculator (backend library)

LIB_DEPENDS=	cln.4:${PORTSDIR}/math/cln

USE_GNOME=	glib20 gnomehack gnometarget intlhack libxml2
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s|docs||g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
