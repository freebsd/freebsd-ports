# New ports collection makefile for:	PiTiVi
# Date created:				20 Dec 2004
# Whom:					Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pitivi
PORTVERSION=	0.1.1
PORTREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Gstreamer based non-linear audio/video editor

CONFLICTS=	gnonlin-0.*

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_GNOME=	gnometarget gnomeprefix
USE_GSTREAMER=	gconf
USE_LIBTOOL_VER=15
USE_PYTHON=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-docs-build
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-Werror||g' \
		${WRKSRC}/gnl/Makefile.in \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
