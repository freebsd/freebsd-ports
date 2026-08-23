PORTNAME=	libnxml
PORTVERSION=	0.18.5
PORTREVISION=	0
CATEGORIES=	textproc devel

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	C library for writing XML 1.0/1.1 files or streams
WWW=		https://github.com/bakulf/libnxml

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		autoreconf libtool pathfix
USE_GITHUB=	yes
GH_ACCOUNT=	bakulf
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
