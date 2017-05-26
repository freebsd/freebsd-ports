# Created by: b.f. <bf@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tinyxml2
PORTVERSION=	4.0.1
PORTEPOCH=	1
CATEGORIES=	textproc

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Small C++ XML Parser

LICENSE=	ZLIB

OPTIONS_DEFINE=	EXAMPLES

CMAKE_ARGS=	-DBUILD_SHARED_LIBS=ON -DBUILD_STATIC_LIBS=ON
USE_LDCONFIG=	yes
USES=		cmake dos2unix pathfix

PLIST_FILES=	include/tinyxml2.h \
		lib/libtinyxml2.a \
		lib/libtinyxml2.so \
		lib/libtinyxml2.so.${PORTVERSION:R:R} \
		lib/libtinyxml2.so.${PORTVERSION} \
		libdata/pkgconfig/tinyxml2.pc
PORTEXAMPLES=	resources xmltest.cpp

GH_ACCOUNT=	leethomason
USE_GITHUB=	yes

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	cd ${WRKSRC}/ && ${COPYTREE_SHARE} "${PORTEXAMPLES}" ${STAGEDIR}${EXAMPLESDIR}/

do-test:
	cd ${WRKSRC}/ && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} xmltest && ./xmltest

.include <bsd.port.mk>
