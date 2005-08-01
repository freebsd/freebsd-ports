# New ports collection makefile for:	fxscintilla
# Date created:				16 June 2004
# Whom:                 		Alexander Novitsky <alecn2002@yandex.ru>
#
# $FreeBSD$
#

PORTNAME=	fxscintilla
PORTVERSION=	1.63
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	alecn2002@yandex.ru
COMMENT=	A Fox toolkit reimplementation of Scintilla editing widget

GNU_CONFIGURE=	yes

USE_LIBTOOL_VER=	15
USE_REINPLACE=	yes
CONFIGURE_ARGS+=	--enable-shared --disable-static
INSTALLS_SHLIB=	yes

OPTIONS=	FOX10 "FOX1.0 support (FOX1.4 by default)" off
OPTIONS=	FOX12 "FOX1.2 support (FOX1.4 by default)" off

.include <bsd.port.pre.mk>

.if defined(WITH_FOX10)
FOX_LIB_VER=	1.0.0
LIB_DEPENDS+=	FOX-${FOX_LIB_VER}:${PORTSDIR}/x11-toolkits/fox
CONFIGURE_ARGS+=	--with-fox-1-0
.elif defined(WITH_FOX12)
FOX_LIB_VER=	1.2
LIB_DEPENDS+=	FOX-${FOX_LIB_VER}:${PORTSDIR}/x11-toolkits/fox12
CONFIGURE_ARGS+=	--with-fox-1-2
.else
FOX_LIB_VER=	1.4
LIB_DEPENDS+=	FOX-${FOX_LIB_VER}:${PORTSDIR}/x11-toolkits/fox-devel
CONFIGURE_ARGS+=	--with-fox-1-4
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lFOX-${FOX_LIB_VER}|"-lFOX-${FOX_LIB_VER} ${PTHREAD_LIBS}"|' \
		${WRKSRC}/configure ${WRKSRC}/tests/Makefile.in

.include <bsd.port.post.mk>
