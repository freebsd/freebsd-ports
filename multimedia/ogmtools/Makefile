# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ogmtools
PORTVERSION=	1.5
PORTREVISION=	15
CATEGORIES=	multimedia audio
MASTER_SITES=	http://www.bunkus.org/videotools/ogmtools/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Tools to extract from/get info about/create OGG media streams

LIB_DEPENDS=	libvorbis.so:audio/libvorbis

USES=	tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ogg-prefix=${LOCALBASE} \
		--with-vorbis-prefix=${LOCALBASE}

OPTIONS_DEFINE=	DVDREAD
OPTIONS_DEFAULT=	DVDREAD
DVDREAD_DESC=	DVD title chapter extraction via libdvdread

DVDREAD_LIB_DEPENDS=	libdvdread.so:multimedia/libdvdread
DVDREAD_CONFIGURE_ON=	--with-dvdread \
			--with-dvdread-includes=${LOCALBASE} \
			--with-dvdread-libs=${LOCALBASE}
DVDREAD_CONFIGURE_OFF=	--without-dvdread
OPTIONS_SUB=	yes

post-patch:
# disable GNU auto* tools
	@${FIND} ${WRKSRC} -type f -name "Makefile.in" | ${XARGS} \
		-n 10 ${REINPLACE_CMD} -E -e \
		's!^(ACLOCAL|AUTOCONF|AUTOMAKE|AUTOHEADER).+$$!\1=${TRUE}!'
# C{,XX}FLAGS safeness
	@${REINPLACE_CMD} -E -e \
		's|^(CFLAGS).*(-DLINUX)|\1=${CFLAGS} \2|' \
		${WRKSRC}/avilib/Makefile.in
	@${REINPLACE_CMD} -E -e \
		's|^(CFLAGS[[:space:]]*)=|\1+=|; \
		s|^(CXXFLAGS[[:space:]]*)=|\1+=|' \
		${WRKSRC}/Makefile.in

post-configure:
# malloc.h -> stdlib.h
# stdint.h -> inttypes.h
	@${FIND} ${WRKSRC} -type f | ${XARGS} \
		-n 10 ${REINPLACE_CMD} -E -e \
		's!malloc.h!stdlib.h!; \
		s|stdint.h|inttypes.h|'

.include <bsd.port.mk>
