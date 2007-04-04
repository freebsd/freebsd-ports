# New ports collection makefile for:	lineak-xosdplugin
# Date created:		2004-12-29
# Whom:			Kay Lehmann <kay_lehmann@web.de>
#
# $FreeBSD$
#

PORTNAME=	lineak-xosdplugin
PORTVERSION=	0.9
CATEGORIES=	sysutils deskutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=lineak
DIST_SUBDIR=	lineak

MAINTAINER=	kay_lehmann@web.de
COMMENT=	Xosd-plugin for lineakd

LIB_DEPENDS=	lineak.8:${PORTSDIR}/sysutils/lineakd \
		xosd.4:${PORTSDIR}/misc/xosd

USE_GMAKE=	yes
USE_XLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--program-prefix=''
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

MAN1=		lineak_xosdplugin.1
MAN_COMPRESSED=	yes
PLIST_FILES=	lib/lineakd/plugins/xosdplugin.la \
		lib/lineakd/plugins/xosdplugin.so

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		Configure fails to find lineakd
#USE_GCC=	3.4
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-ldl||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-O2||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/configure

.include <bsd.port.post.mk>
