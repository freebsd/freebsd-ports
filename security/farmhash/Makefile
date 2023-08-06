PORTNAME=	farmhash
DISTVERSION=	g20190513
CATEGORIES=	security

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Hash functions for strings and other data
WWW=		https://github.com/google/farmhash

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf compiler:c++11-lib gmake libtool
USE_CXXSTD=	c++14
USE_GITHUB=	yes
GH_ACCOUNT=	google
GH_TAGNAME=	0d859a8
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

PLIST_FILES=	include/farmhash.h \
		lib/libfarmhash.a \
		lib/libfarmhash.so \
		lib/libfarmhash.so.0 \
		lib/libfarmhash.so.0.0.0
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
