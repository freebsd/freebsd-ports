# Created by: Jim Mock <jim@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ayttm
PORTVERSION=	0.5.0.111
PORTREVISION=	7
CATEGORIES=	net-im
MASTER_SITES=	SF/ayttm/ayttm/${PORTVERSION:R}-${PORTVERSION:E}/
DISTNAME=	${PORTNAME}-${PORTVERSION:R}-${PORTVERSION:E}

MAINTAINER=	unixmania@gmail.com
COMMENT=	A "chat" program that combines AIM, ICQ, and Yahoo! Chat into one

LIB_DEPENDS=	libaudiofile.so:${PORTSDIR}/audio/libaudiofile \
		jasper.4:${PORTSDIR}/graphics/jasper \
		libgpgme.so:${PORTSDIR}/security/gpgme \
		pspell.16:${PORTSDIR}/textproc/aspell

OPTIONS_DEFINE=	ESOUND AIM_TOC ICQ_TOC
AIM_TOC_DESC=	Include aim-toc service
ICQ_TOC_DESC=	Include icq-toc service

USE_BZIP2=	yes
USE_XORG=	xpm xscrnsaver
USE_GNOME=	gtk20
USE_OPENSSL=	yes
USES=		gmake pkgconfig
USE_AUTOTOOLS=	libltdl libtool
CONFIGURE_ARGS=	--enable-oscar --disable-workwizu --enable-smtp --enable-lj \
		--disable-arts

MAN1=		ayttm.1

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MESOUND}
USE_GNOME+=	esound
.else
CONFIGURE_ARGS+=	--disable-esd
.endif

.if ${PORT_OPTIONS:MAIM_TOC}
CONFIGURE_ARGS+=	--enable-aim-toc
PLIST_SUB+=		AIM_TOC=""
.else
PLIST_SUB+=		AIM_TOC="@comment "
.endif

.if ${PORT_OPTIONS:MICQ_TOC}
CONFIGURE_ARGS+=	--enable-icq-toc
PLIST_SUB+=		ICQ_TOC=""
.else
PLIST_SUB+=		ICQ_TOC="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-L/usr/local/lib||g ; \
		 s|-lpthread|${PTHREAD_LIBS}|g ; \
		 /CFLAGS=/s|-pthread|${PTHREAD_CFLAGS}|g ; \
		 s|-DGTK_DISABLE_DEPRECATED||g ; \
		 /LIBS=/s|-L/usr/X11R6/lib||g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|/gnome/apps/Internet|/applications|g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|-L/usr/local/lib/pth/||g ; \
		 s|-lproxy|../libproxy/libproxy.a|g' ${WRKSRC}/src/Makefile.in

.include <bsd.port.post.mk>
