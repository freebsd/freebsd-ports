# New ports collection makefile for:	multimedia/toxine
# Date created:			3 August 2005
# Whom:				Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	toxine
PORTVERSION=	0.6.3
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	toxine

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Text user interface using the xine library

LIB_DEPENDS=	xine.15:${PORTSDIR}/multimedia/libxine

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -I${X11BASE}/lib"

MAN1=		toxine.1

OPTIONS=	AALIB "Enable aalib support" on \
		LIBCACA "Enable libcaca support" on \
		OPTIMIZED_CFLAGS "Enable compilation optimizations" on

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 502000
LIB_DEPENDS+=	readline.5:${PORTSDIR}/devel/readline
CONFIGURE_ARGS+=--with-readline=${LOCALBASE}
.endif

.if ${OSVERSION} < 500000
EXTRA_PATCHES=	${FILESDIR}/extra-patch-main.c
.endif

.if !defined(WITHOUT_AALIB)
LIB_DEPENDS+=	aa.1:${PORTSDIR}/graphics/aalib
PLIST_SUB+=	AALIB=""
.else
PLIST_SUB+=	AALIB="@comment "
.endif

.if !defined(WITHOUT_LIBCACA)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libcaca.a:${PORTSDIR}/graphics/libcaca
PLIST_SUB+=	LIBCACA=""
.else
PLIST_SUB+=	LIBCACA="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|alsa09|oss|g' ${WRKSRC}/misc/dvdplayer.sh.in
.if defined(WITHOUT_OPTIMIZED_CFLAGS)
	@${REINPLACE_CMD} -e 's|-mpreferred-stack-boundary=2||g ; \
		s|-fno-strict-aliasing||g ; \
		s|-fschedule-insns2||g ; \
		s|-mwide-multiply||g ; \
		s|-falign-functions=4||g ; \
		s|-falign-loops=4||g ; \
		s|-falign-jumps=4||g ; \
		s|-fomit-frame-pointer||g ; \
		s|-fexpensive-optimizations||g ; \
		s|-ffast-math||g ; \
		s|-funroll-loops||g ; \
		s|-finline-functions||g' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
.endif

.include <bsd.port.post.mk>
