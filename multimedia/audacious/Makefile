# Created by: Zastupov Stepan [RedChrom] <redchrom@mail.ru>
# $FreeBSD$

PORTNAME=	audacious
PORTVERSION=	3.10.1
CATEGORIES=	multimedia audio
MASTER_SITES=	https://distfiles.audacious-media-player.org/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lightweight and versatile audio player

LICENSE=	BSD2CLAUSE BSD3CLAUSE
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig

USES=		compiler:c++11-lib desktop-file-utils gettext-tools gmake \
		gnome localbase pkgconfig tar:bzip2
USE_XORG=	x11 sm
USE_GNOME=	gtk20 glib20 cairo
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
SUB_FILES=	pkg-message

CONFLICTS_INSTALL=	audacious-gtk3-3.*

CONFIGURE_ARGS=	--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig \
		--enable-gtk \
		--without-buildstamp

OPTIONS_DEFINE=	ICONV NLS EXECINFO
OPTIONS_DEFAULT=ICONV EXECINFO
OPTIONS_SUB=	yes
EXECINFO_DESC=	Build with libexecinfo support

ICONV_USES=	iconv

NLS_USES=	gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

post-patch:
	@${REINPLACE_CMD} -e 's| $${MFLAGS}||g' \
		${WRKSRC}/buildsys.mk.in

post-patch-NLS-off:
	${REINPLACE_CMD} -e 's,po,,' ${WRKSRC}/Makefile

post-patch-EXECINFO-on:
	@${REINPLACE_CMD} 's|-lm |-lm -lexecinfo |' \
		${WRKSRC}/src/audacious/Makefile
	@${REINPLACE_CMD} 's|-laudcore|-laudcore -lexecinfo|' \
		${WRKSRC}/audacious.pc.in

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/aud*
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib*

.include <bsd.port.mk>
