# Created by: b.f. <bf@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tinyxml2
PORTVERSION=	20131105
CATEGORIES=	textproc
MASTER_SITES=	LOCAL/bf GH

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Small C++ XML Parser

LICENSE=	ZLIB

USE_DOS2UNIX=	yes
USE_GITHUB=	yes
USE_LDCONFIG=	yes
USES=		cmake

GH_ACCOUNT=	leethomason
GH_COMMIT=	370761b
GH_TAGNAME=	${GH_COMMIT}

PLIST_FILES=	include/tinyxml2.h \
		lib/libtinyxml2.a \
		lib/libtinyxml2.so \
		lib/libtinyxml2.so.1 \
		lib/libtinyxml2.so.1.0.12 \
		libdata/pkgconfig/tinyxml2.pc

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's@(DESTINATION )(.*)(/pkgconfig)@\1${PREFIX}/libdata\3@' \
		${WRKSRC}/CMakeLists.txt

check regression-test test: build
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test ; \
	./test

.if ${PORT_OPTIONS:MEXAMPLES}
PORTEXAMPLES=	xmltest.cpp resources

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	@cd ${WRKSRC} ; ${COPYTREE_SHARE} "${PORTEXAMPLES}" ${EXAMPLESDIR}

.endif

.include <bsd.port.mk>
