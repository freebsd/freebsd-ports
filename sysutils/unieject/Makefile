# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	unieject
PORTVERSION=	6
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Eject(1) replacement

LICENSE=	GPLv2

LIB_DEPENDS=	libconfuse.so:${PORTSDIR}/devel/libconfuse \
		libpcre.so:${PORTSDIR}/devel/pcre \
		libcdio.so:${PORTSDIR}/sysutils/libcdio

USE_BZIP2=	yes
USES=		pathfix pkgconfig gettext iconv
USE_GNOME=	glib20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-silent-rules \
		--disable-doc
USE_LDCONFIG=	yes

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
