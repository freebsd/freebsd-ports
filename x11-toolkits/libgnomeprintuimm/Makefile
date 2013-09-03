# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libgnomeprintuimm
PORTVERSION=	2.5.2
PORTREVISION=	9
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	bland@FreeBSD.org
COMMENT=	C++ wrappers for the GNOME print support library

LIB_DEPENDS=	gtkmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24 \
		gnomeprintmm-2.5.2:${PORTSDIR}/print/libgnomeprintmm
BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4

USE_AUTOTOOLS=	libtool
USE_BZIP2=	yes
USES=		gmake pkgconfig
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
