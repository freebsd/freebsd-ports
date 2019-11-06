# $FreeBSD$

PORTNAME=	libcyaml
DISTVERSION=	0.1.0
PORTREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C library for reading and writing YAML

BROKEN=		unfetchable

LICENSE=	ISCL

LIB_DEPENDS=	libyaml.so:textproc/libyaml

USES=		compiler:c11 gmake localbase:ldflags
USE_GITLAB=	yes
GL_SITE=	https://git.zrythm.org
GL_ACCOUNT=	zrythm
GL_COMMIT=	3b568c9df39b5a95f1d652db43414fada3b1cc61
USE_LDCONFIG=	yes

PLIST_FILES=	include/cyaml/cyaml.h \
		lib/libcyaml.a \
		lib/libcyaml.so \
		lib/libcyaml.so.0 \
		lib/libcyaml.so.0.1.0 \
		libdata/pkgconfig/libcyaml.pc

.include <bsd.port.mk>
