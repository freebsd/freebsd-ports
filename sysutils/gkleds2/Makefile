# New ports collection makefile for:	gkleds2
# Date Created:		Dec 10 2002
# Whom:			Jan Stocker <Jan.Stocker@t-online.de>
#
# $FreeBSD$
#

PORTNAME=	gkleds2
PORTVERSION=	0.8.2
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://heim.ifi.uio.no/~oyvinha/files/files/
DISTNAME=	gkleds-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GKrellM Leds for CapsLock, NumLock and ScrollLock

BUILD_DEPENDS=	${X11BASE}/include/gkrellm2/gkrellm.h:${PORTSDIR}/sysutils/gkrellm2
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm2

USE_GNOME=	gnometarget gtk20
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

PLIST_FILES=	libexec/gkrellm2/plugins/gkleds.so

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g ; \
		 s|GK_LDFLAGS|GKM_LDFLAGS|g' ${WRKSRC}/src/Makefile.in

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/.libs/gkleds.so \
		${PREFIX}/libexec/gkrellm2/plugins

.include <bsd.port.mk>
