# New ports collection makefile for:   	fltk
# Date created:				11 February 1999
# Whom:                			Dima Sivachenko <dima@Chg.RU>
#
# $FreeBSD$
#

PORTNAME=	fltk
PORTVERSION=	${VERSION}
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.fltk.org/pub/fltk/${VERSION}/ \
		ftp://ftp.chg.ru/pub/X11/fltk/${VERSION}/ \
		ftp://ftp2.easysw.com/pub/fltk/${VERSION}/ \
		ftp://ftp.northamerica.net/pub/ESP/fltk/${VERSION}/ \
		ftp://ftp.funet.fi/mirrors/ftp.easysw.com/pub/fltk/${VERSION}/ \
		ftp://ftp.kddlabs.co.jp/pub/lang/fltk/${VERSION}/
DISTNAME=	${PORTNAME}-${VERSION}-source

MAINTAINER?=	demon@FreeBSD.org
COMMENT?=	C++ graphical user interface for X

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		Xft.2:${PORTSDIR}/x11-fonts/libXft

.if defined(WITH_THREADS)
CONFIGURE_ARGS+=--enable-threads
CPPFLAGS+=	"${PTHREAD_CFLAGS}"
LDFLAGS+=	"${PTHREAD_LIBS}"
.endif

VERSION=	1.1.4
USE_BZIP2=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-shared --enable-xft
# configure ignores ${CXX} and keeps on linking C++ code with ${CC}
CONFIGURE_ENV+=	CC="${CXX}" CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"
WRKSRC=		${WRKDIR}/${PORTNAME}-${VERSION}
USE_X_PREFIX=	yes
USE_MESA=	yes

MAN1=		fluid.1 fltk-config.1
MAN3=		fltk.3

pre-everything::
	@${ECHO_MSG} "===>  You can enable threads support by defining WITH_THREADS"
	@${ECHO_MSG} "===>"

.include <bsd.port.mk>
