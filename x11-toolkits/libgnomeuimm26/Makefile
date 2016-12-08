# Created by: Alexander Nedotsukov <bland@mail.ru>
# $FreeBSD$
#   $MCom: ports/x11-toolkits/libgnomeuimm26/Makefile,v 1.20 2009/09/22 21:23:48 kwm Exp $

PORTNAME=	libgnomeuimm
PORTVERSION=	2.28.0
PORTREVISION=	7
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	bland@FreeBSD.org
COMMENT=	C++ wrapper for libgnomeui library

LIB_DEPENDS=	libgnomemm-2.6.so:x11/libgnomemm26 \
		libgnomecanvasmm-2.6.so:graphics/libgnomecanvasmm26 \
		libgconfmm-2.6.so:devel/gconfmm26 \
		libglademm-2.4.so:devel/libglademm24 \
		libgnomevfsmm-2.6.so:devel/gnome-vfsmm
BUILD_DEPENDS=	gm4:devel/m4

USES=		gmake libtool:keepla pathfix pkgconfig tar:bzip2
USE_XORG=	x11
USE_GNOME=	libgnomeui
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-static
INSTALL_TARGET=	install-strip

PLIST_SUB=	VERSION="2.6" API_VERSION="2.6"

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s/examples//' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "s|\(-lglibmm\)|-L\$$(GMM_PROCDIR)/../.. \1|" \
		${WRKSRC}/tools/extra_defs_gen/Makefile.in

.include <bsd.port.mk>
