# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	unieject
PORTVERSION=	6
PORTREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Eject(1) replacement

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libconfuse.so:devel/libconfuse \
		libpcre.so:devel/pcre \
		libcdio.so:sysutils/libcdio

USES=		tar:bzip2 pathfix pkgconfig gettext iconv libtool
USE_GNOME=	glib20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-silent-rules \
		--disable-doc
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e \
		'/-D_POSIX_C_SOURCE/s|^CPPFLAGS|#CPPFLAGS|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		'/^install-data-am:/s|install-dist_docDATA|| ; \
		 /^install-data-am:/s|install-dist_htmlDATA||' ${WRKSRC}/Makefile.in

post-install:
	${INSTALL_DATA} ${WRKSRC}/unieject.conf.sample ${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
