PORTNAME=	libcyaml
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.1
CATEGORIES=	textproc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C library for reading and writing YAML

LICENSE=	ISCL

LIB_DEPENDS=	libyaml.so:textproc/libyaml

USES=		compiler:c11 gmake localbase:ldflags
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	tlsa

TEST_TARGET=	test

PLIST_FILES=	include/cyaml/cyaml.h \
		lib/libcyaml.a \
		lib/libcyaml.so \
		lib/libcyaml.so.1 \
		lib/libcyaml.so.1.3.1 \
		libdata/pkgconfig/libcyaml.pc

post-stage:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libcyaml.so.*

.include <bsd.port.mk>
