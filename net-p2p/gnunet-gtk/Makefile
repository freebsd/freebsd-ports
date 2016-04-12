# Created by: bf
# $FreeBSD$

PORTNAME=	gnunet-gtk
PORTVERSION=	0.10.1
CATEGORIES=	net-p2p ipv6 security
MASTER_SITES=	GNU/gnunet

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK interface to GNUnet

LICENSE=	GPLv3

LIB_DEPENDS=	libgladeui-1.so:devel/glade3 \
		libltdl.so:devel/libltdl \
		libqrencode.so:graphics/libqrencode \
		libgnunetutil.so:net-p2p/gnunet \
		libunique-1.0.so:x11-toolkits/unique

USES=		gmake iconv libtool pathfix pkgconfig
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gtktest \
		--with-gtk-version=2 \
		--with-extractor=${LOCALBASE} \
		--with-gnunet=${LOCALBASE} \
		${ICONV_CONFIGURE_ARG}
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=		DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		's|^\([[:space:]]\)install-docDATA$$|\1|' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|"$${mkinstalldirs}"|"$${MKDIR_P}"|' \
		${WRKSRC}/pixmaps/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in AUTHORS ChangeLog NEWS README
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} \
		${STAGEDIR}${DOCSDIR})
.endfor

.include <bsd.port.mk>
