# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	unieject
PORTVERSION=	6
PORTREVISION=	7
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Eject(1) replacement

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libconfuse.so:devel/libconfuse \
		libpcre.so:devel/pcre \
		libcdio.so:sysutils/libcdio

USES=		gettext gnome iconv libtool pathfix pkgconfig tar:bzip2
USE_GNOME=	glib20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-doc
USE_LDCONFIG=	yes
LLD_UNSAFE=	yes
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
