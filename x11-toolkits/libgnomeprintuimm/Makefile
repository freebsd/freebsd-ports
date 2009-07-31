# New ports collection makefile for:	libgnomeprintuimm
# Date created:				17 December 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libgnomeprintuimm
PORTVERSION=	2.5.2
PORTREVISION=	6
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	bland@FreeBSD.org
COMMENT=	C++ wrappers for the GNOME print support library

LIB_DEPENDS=	gtkmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24 \
		gnomeprintmm-2.5.2:${PORTSDIR}/print/libgnomeprintmm
BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4

USE_AUTOTOOLS=	libtool:15
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack libgnomeprintui
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-static

PLIST_SUB=	VERSION="2.5" API_VERSION="2.6"

post-patch:
	@${REINPLACE_CMD} -e 's|2\.0|2.6|' ${WRKSRC}/tools/m4/Makefile.in
	@${REINPLACE_CMD} -e "s|\(-lglibmm\)|-L\$$(GMM_PROCDIR)/../.. \1|" \
		${WRKSRC}/tools/extra_defs_gen/Makefile.in

.include <bsd.port.mk>
