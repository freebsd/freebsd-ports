# Created by: Mykola Dzham <freebsd@levsha.org.ua>

PORTNAME=	lttoolbox
PORTVERSION=	${APVER}.${APREV}
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Tool for lexical, morphological analysis and generation of words

LICENSE=	GPLv2

BUILD_DEPENDS=	utf8cpp>0:devel/utf8cpp
LIB_DEPENDS=	libicuio.so:devel/icu \
		libxml2.so:textproc/libxml2

USES=		autoreconf compiler:c++14-lang libtool pathfix pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	apertium
USE_LDCONFIG=	yes

APVER=		3.6
APREV=		0

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

CFLAGS+=	-I${LOCALBASE}/include/utf8cpp

PLIST_SUB+=	APVER="${APVER}"

.include <bsd.port.mk>
