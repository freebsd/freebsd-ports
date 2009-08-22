# New ports collection makefile for:	lineak-xosdplugin
# Date created:		2004-12-29
# Whom:			Kay Lehmann <kay_lehmann@web.de>
#
# $FreeBSD$
#

PORTNAME=	lineak-xosdplugin
PORTVERSION=	0.9
PORTREVISION=	4
CATEGORIES=	sysutils deskutils
MASTER_SITES=	SF/lineak/lineak_xosdplugin/${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	lineak

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Xosd-plugin for lineakd

LIB_DEPENDS=	lineak.8:${PORTSDIR}/sysutils/lineakd \
		xosd.4:${PORTSDIR}/misc/xosd

USE_GMAKE=	yes
USE_XORG=	x11 xext xt
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--program-prefix=''
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

MAN1=		lineak_xosdplugin.1
MAN_COMPRESSED=	yes
PLIST_FILES=	lib/lineakd/plugins/xosdplugin.la \
		lib/lineakd/plugins/xosdplugin.so

post-patch:
	@${REINPLACE_CMD} -e 's|-ldl||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-O2||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/configure

.include <bsd.port.mk>
