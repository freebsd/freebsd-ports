# Created by: Jesse <jessefrgsmith@yahoo.ca>
# $FreeBSD$

PORTNAME=	imagination
PORTVERSION=	3.0
PORTREVISION=	5
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	jessefrgsmith@yahoo.ca
COMMENT=	DVD slideshow maker

LIB_DEPENDS=	libsox.so:audio/sox \
		libavcodec.so:multimedia/ffmpeg

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
USES=		gmake pkgconfig libtool
USE_GNOME=	gtk20 intltool libxslt
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes
NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext

post-patch:
	@${REINPLACE_CMD} '/^SUBDIRS =/s/doc//' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} '/^imagination_LDADD =/s/$$/ -lm/' \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
