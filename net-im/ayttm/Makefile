# Created by: Jim Mock <jim@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ayttm
PORTVERSION=	0.6.3
CATEGORIES=	net-im
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Chat program that combines AIM, ICQ, and Yahoo! Chat into one

LICENSE=	GPLv2 # (or later)

LIB_DEPENDS=	libaudiofile.so:${PORTSDIR}/audio/libaudiofile \
		libjasper.so:${PORTSDIR}/graphics/jasper \
		libgpgme.so:${PORTSDIR}/security/gpgme \
		libpspell.so:${PORTSDIR}/textproc/aspell \
		libenchant.so:${PORTSDIR}/textproc/enchant

OPTIONS_DEFINE=	ESOUND YAHOO
OPTIONS_SUB=	yes
YAHOO_DESC=	Include Yahoo service

USE_BZIP2=	yes
USES=		gettext gmake iconv pkgconfig
USE_XORG=	xpm xscrnsaver
USE_GNOME=	gtk20
USE_OPENSSL=	yes
USE_AUTOTOOLS=	libtool libltdl
CONFIGURE_ARGS=	--enable-oscar --disable-workwizu --enable-smtp --enable-lj \
		--disable-arts

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

ESOUND_CONFIGURE_ENABLE=	esd
ESOUND_USE=		GNOME=esound

YAHOO_LIB_DEPENDS=	libyahoo2.so:${PORTSDIR}/net-im/libyahoo2
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
