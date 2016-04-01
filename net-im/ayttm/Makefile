# Created by: Jim Mock <jim@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ayttm
PORTVERSION=	0.6.3
PORTREVISION=	2
CATEGORIES=	net-im
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Chat program that combines AIM, ICQ, and Yahoo! Chat into one

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libaudiofile.so:audio/libaudiofile \
		libltdl.so:devel/libltdl \
		libjasper.so:graphics/jasper \
		libgpgme.so:security/gpgme \
		libenchant.so:textproc/enchant

OPTIONS_DEFINE=	ESOUND YAHOO
OPTIONS_SUB=	yes
YAHOO_DESC=	Include Yahoo service

USES=		gettext gmake iconv libtool pkgconfig shebangfix tar:bzip2
USE_XORG=	xpm xscrnsaver
USE_GNOME=	gtk20
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-oscar --disable-workwizu --enable-smtp --enable-lj \
		--disable-arts
SHEBANG_FILES=	${WRKSRC}/modules/image_filter/ayttm_streamer_wrapper

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

ESOUND_CONFIGURE_ENABLE=	esd
ESOUND_USE=		GNOME=esound

YAHOO_LIB_DEPENDS=	libyahoo2.so:net-im/libyahoo2
YAHOO_CONFIGURE_ENABLE=	yahoo

post-patch:
	@${REINPLACE_CMD} -e \
		's|-Wl,--no-add-needed|| ; \
		 s|-L/usr/local/lib|| ; \
		 s|-lpthread|-pthread| ; \
		 /LIBS=/s|-L/usr/X11R6/lib||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|/gnome/apps/Internet|/applications|' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|-L/usr/local/lib/pth/||' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
