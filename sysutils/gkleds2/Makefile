# Created by: Jan Stocker <Jan.Stocker@t-online.de>
# $FreeBSD$

PORTNAME=	gkleds2
PORTVERSION=	0.8.2
PORTREVISION=	9
CATEGORIES=	sysutils
MASTER_SITES=	http://heim.ifi.uio.no/~oyvinha/files/files/
DISTNAME=	gkleds-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GKrellM Leds for CapsLock, NumLock, and ScrollLock

LICENSE=	GPLv2 # only
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/gkrellm2/gkrellm.h:sysutils/gkrellm2
RUN_DEPENDS=	gkrellm:sysutils/gkrellm2

USES=		gmake libtool pkgconfig
GNU_CONFIGURE=	yes
USE_XORG=	x11 xtst
USE_GNOME=	gtk20
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	libexec/gkrellm2/plugins/gkleds.so

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g ; \
		 s|GK_LDFLAGS|GKM_LDFLAGS|g' ${WRKSRC}/src/Makefile.in

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/gkrellm2/plugins
	${INSTALL_LIB} ${WRKSRC}/src/.libs/gkleds.so \
		${STAGEDIR}${PREFIX}/libexec/gkrellm2/plugins

.include <bsd.port.mk>
