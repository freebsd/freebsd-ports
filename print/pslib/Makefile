# ex:ts=8
# Ports collection makefile for:	pslib
# Date created:			Jul 13, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	pslib
PORTVERSION=	0.2.5
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A C-library for generating multi page PostScript documents

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png

USE_GNOME=	gnomehack gnometarget intlhack pkgconfig
USE_GETTEXT=	yes
USE_LIBTOOL_VER=	15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
