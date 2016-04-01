# Created by: Kay Lehmann <kay_lehmann@web.de>
# $FreeBSD$

PORTNAME=	lineak-xosdplugin
PORTVERSION=	0.9
PORTREVISION=	10
CATEGORIES=	sysutils deskutils
MASTER_SITES=	SF/lineak/lineak_xosdplugin/${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	lineak

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Xosd-plugin for lineakd

LICENSE=	GPLv2

LIB_DEPENDS=	libxosd.so:misc/xosd \
		liblineak.so:sysutils/lineakd

USES=		gmake libtool
USE_LDCONFIG=	yes
USE_XORG=	x11 xext xt
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	ac_cv_path_xosd_config_script="${TRUE}" \
		kde_cv_prog_cxx_fno_check_new=no
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

PLIST_FILES=	lib/lineakd/plugins/xosdplugin.so \
		man/man1/lineak_xosdplugin.1.gz

post-patch:
	@${REINPLACE_CMD} -e \
		's|"-O2 $$CXXFLAGS"|"$$CXXFLAGS"| ; \
		 /LDFLAGS/s|-ldl||' ${WRKSRC}/configure

.include <bsd.port.mk>
