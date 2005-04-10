# New ports collection makefile for:	lineak_xosdplugin
# Date created:		2004-12-29
# Whom:			Kay Lehmann <kay_lehmann@web.de>
#
# $FreeBSD$
#

PORTNAME=	lineak_xosdplugin
PORTVERSION=	0.8.3
CATEGORIES=	sysutils deskutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=lineak
DIST_SUBDIR=	lineak

MAINTAINER=	kay_lehmann@web.de
COMMENT=	Xosd-plugin for lineakd

LIB_DEPENDS=	lineak.8:${PORTSDIR}/sysutils/lineakd \
		xosd.4:${PORTSDIR}/misc/xosd

USE_GMAKE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--program-prefix=''
USE_REINPLACE=	yes
USE_LIBTOOL_VER=15
INSTALLS_SHLIB=	yes

MAN1=		lineak_xosdplugin.1
PLIST_FILES=	lib/lineakd/plugins/xosdplugin.so

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
USE_GCC=	3.4
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-ldl||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-O2||' ${WRKSRC}/configure

.include <bsd.port.post.mk>
