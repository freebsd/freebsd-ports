# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	inotify-tools
DISTVERSION=	3.20.1
CATEGORIES=	sysutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Command-line utilities to watch for file events

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libinotify.so:devel/libinotify

USES=		autoreconf gmake libtool localbase
USE_GITHUB=	yes
GH_ACCOUNT=	rvoicilas
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-doxygen
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	STATIC
OPTIONS_SUB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|stat64|stat|' \
		${WRKSRC}/src/common.c \
		${WRKSRC}/libinotifytools/src/inotifytools.c

post-build-STATIC-on:
	@cd ${WRKSRC}/src && \
		${CC} -pthread ${LDFLAGS} -static -o inotifywait.static inotifywait.o common.o ../libinotifytools/src/.libs/libinotifytools.a ${LOCALBASE}/lib/libinotify.a && \
		${CC} -pthread ${LDFLAGS} -static -o inotifywatch.static inotifywatch.o common.o ../libinotifytools/src/.libs/libinotifytools.a ${LOCALBASE}/lib/libinotify.a

post-install-STATIC-on:
	${INSTALL_PROGRAM} ${WRKSRC}/src/inotifywait.static ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/inotifywatch.static ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
