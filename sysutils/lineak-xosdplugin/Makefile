# Created by: Kay Lehmann <kay_lehmann@web.de>
# $FreeBSD$

PORTNAME=	lineak-xosdplugin
PORTVERSION=	0.9
PORTREVISION=	7
CATEGORIES=	sysutils deskutils
MASTER_SITES=	SF/lineak/lineak_xosdplugin/${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	lineak

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Xosd-plugin for lineakd

LICENSE=	GPLv2

LIB_DEPENDS=	libxosd.so:${PORTSDIR}/misc/xosd \
		liblineak.so:${PORTSDIR}/sysutils/lineakd

USE_XORG=	x11 xext xt
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_path_xosd_config_script="${TRUE}"
USE_LDCONFIG=	yes

CFLAGS+=		-fPIC
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		lineak_xosdplugin.1
PLIST_FILES=	lib/lineakd/plugins/xosdplugin.la \
		lib/lineakd/plugins/xosdplugin.so \
		man/man1/lineak_xosdplugin.1.gz

post-patch:
	@${REINPLACE_CMD} -e \
		's|"-O2 $$CXXFLAGS"|"$$CXXFLAGS"| ; \
		 s|echo aout|echo elf| ; \
		 /LDFLAGS/s|-ldl||' ${WRKSRC}/configure

.include <bsd.port.mk>
