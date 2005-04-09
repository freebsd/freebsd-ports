# New ports collection makefile for:	lineak_defaultplugin
# Date created:		2004-12-29
# Whom:			Kay Lehmann <kay_lehmann@web.de>
#
# $FreeBSD$
#

PORTNAME=	lineak_defaultplugin
PORTVERSION=	0.8.3
CATEGORIES=	sysutils deskutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	lineak
DIST_SUBDIR=	lineak

MAINTAINER=	kay_lehmann@web.de
COMMENT=	Default plugins for lineakd

LIB_DEPENDS=	lineak.8:${PORTSDIR}/sysutils/lineakd

USE_LIBTOOL_VER=15
USE_GMAKE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CONFIGURE_ARGS+=	--program-prefix=''
USE_REINPLACE=	yes

MAN1=		lineak_defaultplugin.1
PLIST_FILES=	lib/lineakd/plugins/defaultplugin.so \
		lib/lineakd/plugins/mediadetectplugin.so

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
# lineakd is compiled with 3.4 on FreeBSD 4.x, so plugins must be too
USE_GCC=	3.4
GNU_CONFIGURE=	yes
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-ldl||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-O2||' ${WRKSRC}/configure

.include <bsd.port.post.mk>
