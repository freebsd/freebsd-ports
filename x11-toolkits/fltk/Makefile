# New ports collection makefile for:   	fltk
# Date created:				11 February 1999
# Whom:                			Dima Sivachenko <dima@Chg.RU>
#
# $FreeBSD$
#

PORTNAME=	fltk
PORTVERSION?=	${_PORTVERSION}
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.fltk.org/pub/fltk/${VERSION}/ \
		ftp://ftp.chg.ru/pub/X11/fltk/${VERSION}/ \
		ftp://ftp2.easysw.com/pub/fltk/${VERSION}/ \
		ftp://ftp.northamerica.net/pub/ESP/fltk/${VERSION}/ \
		ftp://ftp.funet.fi/mirrors/ftp.easysw.com/pub/fltk/${VERSION}/ \
		ftp://ftp.kddlabs.co.jp/pub/lang/fltk/${VERSION}/
DISTNAME=	${PORTNAME}-${VERSION}-source

MAINTAINER?=	demon@FreeBSD.org

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg

.if defined(WITH_XUNICODE)
PATCH_VERSION=	20010114
_PORTVERSION+=	${VERSION}.${PATCH_VERSION}

PORTREVISION=	2
PKGNAMESUFFIX=	-xunicode

PATCH_SITES=	http://www.ab.wakwak.com/~tino/jatk/fltk/
PATCHFILES=	${PORTNAME}-${VERSION}${PKGNAMESUFFIX}-${PATCH_VERSION}.diff
PATCH_DIST_STRIP=	-p1

BUILD_DEPENDS=	${X11BASE}/include/xunicode/xunicode.h:${PORTSDIR}/converters/xunicode

CONFIGURE_ENV=	CXXFLAGS=-DUSE_XUNICODE
.else
_PORTVERSION+=	${VERSION}
.endif

VERSION=	1.1.2
USE_BZIP2=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ENV+=	CPPFLAGS="${PTHREAD_CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${PTHREAD_LIBS} -L${LOCALBASE}/lib"
WRKSRC=		${WRKDIR}/${PORTNAME}-${VERSION}
USE_X_PREFIX=	yes
USE_MESA=	yes

MAN1=		fluid.1 fltk-config.1
MAN3=		fltk.3

.if defined(WITH_XUNICODE)
post-extract:
	cd ${WRKSRC} && ${LN} -s ${X11BASE}/include/xunicode
.endif

.include <bsd.port.mk>
