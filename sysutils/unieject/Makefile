PORTNAME=	unieject
DISTVERSION=	6
PORTREVISION=	9
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Eject(1) replacement
WWW=		https://github.com/Flameeyes/unieject

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Abandonware, upstream repo deprecated May 17, 2020
EXPIRATION_DATE=2024-07-31

LIB_DEPENDS=	libconfuse.so:devel/libconfuse \
		libcdio.so:sysutils/libcdio

USES=		gettext gnome iconv libtool localbase:ldflags \
		pathfix pkgconfig tar:bzip2
USE_GNOME=	glib20
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=	--disable-doc

post-patch:
	@${REINPLACE_CMD} -e \
		'/-D_POSIX_C_SOURCE/s|^CPPFLAGS|#CPPFLAGS|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		'/^install-data-am:/s|install-dist_docDATA|| ; \
		 /^install-data-am:/s|install-dist_htmlDATA||' ${WRKSRC}/Makefile.in

post-install:
	${INSTALL_DATA} ${WRKSRC}/unieject.conf.sample ${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
