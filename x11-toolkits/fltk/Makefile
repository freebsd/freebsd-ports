# New ports collection makefile for:   	fltk
# Date created:				11 February 1999
# Whom:                			Dima Sivachenko <dima@Chg.RU>
#
# $FreeBSD$
#

PORTNAME=	fltk
PORTVERSION?=	${_PORTVERSION}
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.fltk.org/pub/fltk/${VERSION}/ \
		ftp://ftp.chg.ru/pub/X11/fltk/${VERSION}/ \
		ftp://ftp2.easysw.com/pub/fltk/${VERSION}/ \
		ftp://ftp.northamerica.net/pub/ESP/fltk/${VERSION}/ \
		ftp://ftp.funet.fi/mirrors/ftp.easysw.com/pub/fltk/${VERSION}/ \
		ftp://ftp.kddlabs.co.jp/pub/lang/fltk/${VERSION}/
DISTNAME=	${PORTNAME}-${VERSION}-source

MAINTAINER?=	demon@FreeBSD.org

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

VERSION=	1.0.10
USE_BZIP2=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ENV+=	CPPFLAGS="${PTHREAD_CFLAGS}" \
		LDFLAGS="${PTHREAD_LIBS}"
WRKSRC=		${WRKDIR}/${PORTNAME}-${VERSION}
USE_X_PREFIX=	yes
USE_MESA=	yes
MAN1=		fluid.1

.if defined(WITH_XUNICODE)
post-extract:
	cd ${WRKSRC} && ${LN} -s ${X11BASE}/include/xunicode
.endif

post-install:
	@ ${INSTALL_MAN} ${WRKSRC}/documentation/fluid.1 \
		${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/fltk
	for ext in html gif jpg ; do \
		${INSTALL_DATA} ${WRKSRC}/documentation/*.$$ext \
		${PREFIX}/share/doc/fltk; \
	done
	${INSTALL_DATA} ${WRKSRC}/documentation/README \
		${PREFIX}/share/doc/fltk
.endif

.include <bsd.port.mk>
