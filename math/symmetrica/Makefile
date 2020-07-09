# $FreeBSD$

PORTNAME=	symmetrica
DISTVERSION=	3.0.1
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library with a collection of routines for combinatorial mathematics

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		autoreconf gmake libtool
USE_GITLAB=	yes
GL_ACCOUNT=	sagemath
GL_COMMIT=	e29c85915f368d6fb2f89d703b6695ff29ab9eae
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

PLIST_FILES=	include/symmetrica.h \
		include/${PORTNAME}/def.h \
		include/${PORTNAME}/macro.h \
		lib/libsymmetrica.so \
		lib/libsymmetrica.so.2 \
		lib/libsymmetrica.so.2.0.0

.include <bsd.port.mk>
