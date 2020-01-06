# $FreeBSD$

PORTNAME=	libcyaml
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.0
PORTREVISION=	1
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
		lib/libcyaml.so.0 \
		lib/libcyaml.so.0.1.0 \
		libdata/pkgconfig/libcyaml.pc

.include <bsd.port.mk>
