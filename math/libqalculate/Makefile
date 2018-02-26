# Created by: Sergey Akifyev <asa@agava.com>
# $FreeBSD$

PORTNAME=	libqalculate
PORTVERSION=	2.2.1
CATEGORIES=	math
MASTER_SITES=	https://github.com/Qalculate/${PORTNAME}/releases/download/v${PORTVERSION}/

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Multi-purpose desktop calculator (backend library)

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libicuuc.so:devel/icu \
		libcurl.so:ftp/curl \
		libgmp.so:math/gmp \
		libmpfr.so:math/mpfr

USES=		gmake gettext iconv libtool localbase \
		ncurses pathfix pkgconfig readline:port
USE_GNOME=	intltool libxml2
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

post-patch-NLS-off:
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s|po ||g' ${WRKSRC}/Makefile.in

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s|docs||g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
