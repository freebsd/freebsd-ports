PORTNAME=	libmrss
DISTVERSION=	0.19.4
CATEGORIES=	textproc

MAINTAINER=	juw@posteo.de
COMMENT=	C library for parsing, writing, and creating RSS
WWW=		https://github.com/bakulf/libmrss/

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libnxml.so:textproc/libnxml

USES=		autoreconf libtool localbase pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	bakulf
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
