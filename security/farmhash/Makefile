# $FreeBSD$

PORTNAME=	farmhash
DISTVERSION=	g20190513
CATEGORIES=	security

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Hash functions for strings and other data

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf compiler:c++11-lib gmake libtool
GNU_CONFIGURE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	google
GH_TAGNAME=	0d859a8
USE_LDCONFIG=	yes

INSTALL_TARGET=	install-strip

PLIST_FILES=	include/farmhash.h \
		lib/libfarmhash.a \
		lib/libfarmhash.so \
		lib/libfarmhash.so.0 \
		lib/libfarmhash.so.0.0.0

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

.include <bsd.port.mk>
