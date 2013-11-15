# Created by: Kay Lehmann <kay_lehmann@web.de>
# $FreeBSD$

PORTNAME=	lineak-defaultplugin
PORTVERSION=	0.9
PORTREVISION=	3
CATEGORIES=	sysutils deskutils
MASTER_SITES=	SF/lineak/lineak_defaultplugin/${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	lineak

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Default plugins for lineakd

LICENSE=	GPLv2

LIB_DEPENDS=	lineak:${PORTSDIR}/sysutils/lineakd

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USE_XORG=	x11 xext xt xtst xfixes
USE_GMAKE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=	--program-prefix=''

PLIST_FILES=	lib/lineakd/plugins/defaultplugin.a \
		lib/lineakd/plugins/defaultplugin.la \
		lib/lineakd/plugins/defaultplugin.so \
		lib/lineakd/plugins/mediadetectplugin.a \
		lib/lineakd/plugins/mediadetectplugin.la \
		lib/lineakd/plugins/mediadetectplugin.so \
		man/man1/lineak_defaultplugin.1.gz \
		etc/media-detect.conf

post-patch:
	@${REINPLACE_CMD} -e 's|-ldl||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-O2||' ${WRKSRC}/configure

.include <bsd.port.mk>
