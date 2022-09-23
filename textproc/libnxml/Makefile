PORTNAME=	libnxml
PORTVERSION=	0.18.3
PORTREVISION=	4
CATEGORIES=	textproc devel
MASTER_SITES=	https://www.autistici.org/bakunin/libnxml/

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	C library for writing XML 1.0/1.1 files or streams
WWW=		https://github.com/bakulf/libnxml

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		libtool pathfix
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
