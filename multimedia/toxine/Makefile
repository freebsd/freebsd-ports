# New ports collection makefile for:	multimedia/toxine
# Date created:			3 August 2005
# Whom:				Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	toxine
PORTVERSION=	0.6.3
PORTREVISION=	7
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	toxine

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Text user interface using the xine library

LIB_DEPENDS=	xine.1:${PORTSDIR}/multimedia/libxine

BROKEN=		does not build
DEPRECATED=	has been inactive for almost 5 years
EXPIRATION_DATE=2009-04-12

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

OPTIONS=	AALIB "Enable aalib support" on \
		LIBCACA "Enable libcaca support" on \
		OPTIMIZED_CFLAGS "Enable compilation optimizations" on

MAN1=		toxine.1

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_AALIB)
LIB_DEPENDS+=	aa.1:${PORTSDIR}/graphics/aalib
PLIST_SUB+=	AALIB=""
.else
PLIST_SUB+=	AALIB="@comment "
.endif

.if !defined(WITHOUT_LIBCACA)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libcaca.a:${PORTSDIR}/graphics/libcaca
CONFIGURE_ARGS+=--disable-cacatest
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
