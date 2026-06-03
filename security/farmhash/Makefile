PORTNAME=	farmhash
DISTVERSION=	1.1
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
GH_TAGNAME=	0d859a811870d10f53a594927d0d0b97573ad06d
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
