# Created by: Jim Mock <jim@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ayttm
PORTVERSION=	0.5.0.111
PORTREVISION=	7
CATEGORIES=	net-im
MASTER_SITES=	SF/ayttm/ayttm/${PORTVERSION:R}-${PORTVERSION:E}/
DISTNAME=	${PORTNAME}-${PORTVERSION:R}-${PORTVERSION:E}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Chat program that combines AIM, ICQ, and Yahoo! Chat into one

LICENSE=	GPLv2

LIB_DEPENDS=	libaudiofile.so:${PORTSDIR}/audio/libaudiofile \
		libjasper.so:${PORTSDIR}/graphics/jasper \
		libgpgme.so:${PORTSDIR}/security/gpgme \
		libpspell.so:${PORTSDIR}/textproc/aspell

OPTIONS_DEFINE=	ESOUND AIM_TOC ICQ_TOC
OPTIONS_SUB=	yes
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

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

AIM_TOC_CONFIGURE_ON=	--enable-aim-toc
ESOUND_CONFIGURE_OFF=	--disable-esd
ESOUND_USE=		GNOME=esound
ICQ_TOC_CONFIGURE_ON=	--enable-icq-toc

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

.include <bsd.port.mk>
