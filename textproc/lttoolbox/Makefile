PORTNAME=	lttoolbox
PORTVERSION=	3.7.1
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Tool for lexical, morphological analysis and generation of words
WWW=		https://wiki.apertium.org/wiki/Lttoolbox

LICENSE=	GPLv2

BUILD_DEPENDS=	utf8cpp>0:devel/utf8cpp
LIB_DEPENDS=	libicuio.so:devel/icu \
		libxml2.so:textproc/libxml2

USES=		autoreconf compiler:c++14-lang libtool pathfix pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	apertium
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

CFLAGS+=	-I${LOCALBASE}/include/utf8cpp
LDFLAGS+=	-lpthread

.include <bsd.port.mk>
