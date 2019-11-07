# Created by: Kay Lehmann <kay_lehmann@web.de>
# $FreeBSD$

PORTNAME=	lineak-defaultplugin
PORTVERSION=	0.9
PORTREVISION=	5
CATEGORIES=	sysutils deskutils
MASTER_SITES=	SF/lineak/lineak_defaultplugin/${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	lineak

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Default plugins for lineakd

LICENSE=	GPLv2

LIB_DEPENDS=	liblineak.so:sysutils/lineakd

USES=		gmake libtool xorg
USE_XORG=	x11 xext xt xtst xfixes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	kde_cv_prog_cxx_fno_check_new=no
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

PLIST_FILES=	lib/lineakd/plugins/defaultplugin.so \
		lib/lineakd/plugins/mediadetectplugin.so \
		man/man1/lineak_defaultplugin.1.gz \
		etc/media-detect.conf

post-patch:
	@${REINPLACE_CMD} -e 's|-ldl||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-O2||' ${WRKSRC}/configure

.include <bsd.port.mk>
