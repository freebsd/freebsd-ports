# $FreeBSD$

PORTNAME=	printsupport
DISTVERSION=	${QT5_VERSION}
CATEGORIES=	print
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt print support module

USES=		compiler:c++11-lang qmake:no_env qt-dist:5,base
USE_QT=		core gui widgets qmake_build buildtools_build
HAS_CONFIGURE=	yes
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

BUILD_WRKSRC=	${WRKSRC}/src/${PORTNAME}
INSTALL_WRKSRC=	${BUILD_WRKSRC}

OPTIONS_DEFINE=	CUPS
OPTIONS_DEFAULT=CUPS
OPTIONS_SUB=	yes

CUPS_CONFIGURE_ON=	-cups
CUPS_CONFIGURE_OFF=	-no-cups
CUPS_LIB_DEPENDS=	libcups.so:print/cups

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCUPS}
QT_DEFINES+=	CUPS
QT_CONFIG+=	cups
MORE_WRKSRCS+=	src/plugins/printsupport
.else
QT_DEFINES+=	-CUPS
QT_CONFIG+=	-cups
.endif

post-configure:
.for d in src/printsupport ${MORE_WRKSRCS}
	${MKDIR} ${WRKSRC}/${d}
	cd ${WRKSRC}/${d} && ${SETENV} ${QMAKE_ENV} ${_QMAKE} ${QMAKE_ARGS} ${WRKSRC}/${d}
.endfor

post-build:
.if ${PORT_OPTIONS:MCUPS}
	@cd ${WRKSRC}/src/plugins/${PORTNAME}/cups && \
		${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} \
		${_MAKE_JOBS} ${MAKE_ARGS} ${ALL_TARGET}
.endif

post-install:
.if ${PORT_OPTIONS:MCUPS}
	@cd ${WRKSRC}/src/plugins/${PORTNAME}/cups && \
		${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} \
		${MAKE_ARGS} ${INSTALL_TARGET}
.endif

.include <bsd.port.mk>
