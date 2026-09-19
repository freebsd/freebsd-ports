PORTNAME=	symmetrica
DISTVERSION=	3.1.0
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library with a collection of routines for combinatorial mathematics
WWW=		https://gitlab.com/sagemath/symmetrica

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		autoreconf gmake libtool pkgconfig
USE_GITLAB=	yes
GL_ACCOUNT=	sagemath
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

PLIST_FILES=	include/symmetrica.h \
		include/${PORTNAME}/def.h \
		include/${PORTNAME}/macro.h \
		lib/libsymmetrica.so \
		lib/libsymmetrica.so.3 \
		lib/libsymmetrica.so.3.0.0 \
		libdata/pkgconfig/symmetrica.pc

.include <bsd.port.mk>
