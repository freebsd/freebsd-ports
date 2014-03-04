# $FreeBSD$

PORTNAME=	printsupport
DISTVERSION=	${QT5_VERSION}
CATEGORIES=	print
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt print support module

USE_QT5=	core gui widgets qmake_build buildtools_build
QT_DIST=	base
HAS_CONFIGURE=	yes
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

BUILD_WRKSRC=	${WRKSRC}/src/${PORTNAME}
INSTALL_WRKSRC=	${BUILD_WRKSRC}

OPTIONS_DEFINE=	CUPS
OPTIONS_DEFAULT=CUPS
OPTIONS_SUB=	yes

CUPS_BUILD_DEPENDS=	${LOCALBASE}/include/cups/cups.h:${PORTSDIR}/print/cups-client
CUPS_CONFIGURE_ON=	-cups
CUPS_CONFIGURE_OFF=	-no-cups

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCUPS}
QT_DEFINES+=	CUPS
QT_CONFIG+=	cups
.else
QT_DEFINES+=	-CUPS
QT_CONFIG+=	-cups
.endif

post-configure:
.if ${PORT_OPTIONS:MCUPS}
	@cd ${WRKSRC}/src/plugins/${PORTNAME}/cups && \
		${SETENV} ${QMAKE_ENV} ${WRKSRC}/bin/qmake ${QMAKE_ARGS}
.endif

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
