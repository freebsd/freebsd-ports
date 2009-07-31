# New ports collection makefile for:	fxscintilla
# Date created:				16 June 2004
# Whom:                 		Alexander Novitsky <alecn2002@yandex.ru>
#
# $FreeBSD$
#

PORTNAME=	fxscintilla
PORTVERSION=	1.71
PORTREVISION=	12
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	A Fox toolkit reimplementation of Scintilla editing widget

USE_AUTOTOOLS=	libtool:15
CONFIGURE_ARGS+=	--enable-shared --disable-static
USE_LDCONFIG=	yes

.if !defined(MASTERDIR)
OPTIONS=	FOX12 "FOX1.2 support (FOX1.6 by default)" off
OPTIONS+=	FOX14 "FOX1.4 support (FOX1.6 by default)" off
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_FOX12)
FOX_LIB_VER=	1.2
LIB_DEPENDS+=	FOX-${FOX_LIB_VER}:${PORTSDIR}/x11-toolkits/fox12
CONFIGURE_ARGS+=	--with-fox-1-2
.elif defined(WITH_FOX14)
FOX_LIB_VER=	1.4
LIB_DEPENDS+=	FOX-${FOX_LIB_VER}:${PORTSDIR}/x11-toolkits/fox14
CONFIGURE_ARGS+=	--with-fox-1-4
.else
FOX_LIB_VER=	1.6
LIB_DEPENDS+=	FOX-${FOX_LIB_VER}:${PORTSDIR}/x11-toolkits/fox16
CONFIGURE_ARGS+=	--with-fox-1-6
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lFOX-${FOX_LIB_VER}|"-lFOX-${FOX_LIB_VER} ${PTHREAD_LIBS}"|' \
		${WRKSRC}/configure ${WRKSRC}/tests/Makefile.in

.include <bsd.port.post.mk>
