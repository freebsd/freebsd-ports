# $FreeBSD$

PORTNAME=	libcyaml
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.1
CATEGORIES=	textproc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C library for reading and writing YAML

LICENSE=	ISCL

LIB_DEPENDS=	libyaml.so:textproc/libyaml

USES=		compiler:c11 gmake localbase:ldflags
USE_GITHUB=	yes
GH_ACCOUNT=	tlsa
USE_LDCONFIG=	yes

PLIST_FILES=	include/cyaml/cyaml.h \
		lib/libcyaml.a \
		lib/libcyaml.so \
		lib/libcyaml.so.1 \
		lib/libcyaml.so.1.0.1 \
		libdata/pkgconfig/libcyaml.pc

post-stage:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libcyaml.so.*

.include <bsd.port.mk>
