# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libgnomeprintuimm
PORTVERSION=	2.5.2
PORTREVISION=	15
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	bland@FreeBSD.org
COMMENT=	C++ wrappers for the GNOME print support library

LIB_DEPENDS=	libgtkmm-2.4.so:x11-toolkits/gtkmm24 \
		libgnomeprintmm-2.5.so:print/libgnomeprintmm
BUILD_DEPENDS=	gm4:devel/m4

USES=		compiler:c++11-lang gmake libtool:keepla pathfix \
		pkgconfig tar:bzip2
USE_CXXSTD=	c++11
USE_GNOME=	gnomeprefix libgnomeprintui
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-static
INSTALL_TARGET=	install-strip

PLIST_SUB=	VERSION="2.5" API_VERSION="2.6"

post-patch:
	@${REINPLACE_CMD} -e 's|2\.0|2.6|' ${WRKSRC}/tools/m4/Makefile.in
	@${REINPLACE_CMD} -e "s|\(-lglibmm\)|-L\$$(GMM_PROCDIR)/../.. \1|" \
		${WRKSRC}/tools/extra_defs_gen/Makefile.in

.include <bsd.port.mk>
