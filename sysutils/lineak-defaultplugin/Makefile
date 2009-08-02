# New ports collection makefile for:	lineak-defaultplugin
# Date created:		2004-12-29
# Whom:			Kay Lehmann <kay_lehmann@web.de>
#
# $FreeBSD$
#

PORTNAME=	lineak-defaultplugin
PORTVERSION=	0.9
PORTREVISION=	2
CATEGORIES=	sysutils deskutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	lineak
DIST_SUBDIR=	lineak

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Default plugins for lineakd

LIB_DEPENDS=	lineak.8:${PORTSDIR}/sysutils/lineakd

USE_AUTOTOOLS=	libtool:22
GNU_CONFIGURE=	yes
USE_XORG=       x11 xext xt xtst xfixes
USE_GMAKE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CONFIGURE_ARGS+=	--program-prefix=''

MAN1=		lineak_defaultplugin.1
MAN_COMPRESSED=	yes
PLIST_FILES=	lib/lineakd/plugins/defaultplugin.a \
		lib/lineakd/plugins/defaultplugin.la \
		lib/lineakd/plugins/defaultplugin.so \
		lib/lineakd/plugins/mediadetectplugin.a \
		lib/lineakd/plugins/mediadetectplugin.la \
		lib/lineakd/plugins/mediadetectplugin.so \
		etc/media-detect.conf

post-patch:
	@${REINPLACE_CMD} -e 's|-ldl||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-O2||' ${WRKSRC}/configure

.include <bsd.port.mk>
