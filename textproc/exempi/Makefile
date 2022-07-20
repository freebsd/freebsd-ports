PORTNAME=	exempi
DISTVERSION=	2.5.2
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://libopenraw.freedesktop.org/download/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Port of Adobe XMP SDK to work on UNIX

BUILD_DEPENDS=	boost-libs>=0:devel/boost-libs
LIB_DEPENDS=	libexpat.so:textproc/expat2

USES=		cpe gmake iconv libtool localbase pathfix tar:bzip2
CPE_VENDOR=	${PORTNAME}_project
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
GNU_CONFIGURE=	yes

pre-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} NOCONFIGURE=1 ./autogen.sh

post-patch:
	@${REINPLACE_CMD} -e 's|$${libdir}/pkgconfig|${PREFIX}/libdata/pkgconfig|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
