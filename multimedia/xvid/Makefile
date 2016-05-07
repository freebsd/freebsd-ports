# Created by: Michael Nottebrock <michaelnottebrock@gmx.net> et al
# $FreeBSD$

PORTNAME=	xvid
PORTVERSION=	1.3.4
PORTEPOCH=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://downloads.xvid.org/downloads/
DISTNAME=	${PORTNAME}core-${PORTVERSION}

MAINTAINER=	riggs@FreeBSD.org
COMMENT=	Opensource MPEG-4 codec, based on OpenDivx

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKDIR}/xvidcore/LICENSE

USES=		gmake
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes
USE_LDCONFIG=	yes

CONFIGURE_ENV+=	ac_cv_prog_ac_yasm=no

PLIST_FILES=	include/xvid.h \
		lib/libxvidcore.a \
		lib/libxvidcore.so \
		lib/libxvidcore.so.4 \
		lib/libxvidcore.so.4.3

WRKSRC=		${WRKDIR}/xvidcore/build/generic

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CONFIGURE_TARGET=	x86_64-portbld-freebsd${OSREL}
.endif
.if ${ARCH} == "amd64" || ${ARCH} == "i386"
BUILD_DEPENDS+=	nasm:devel/nasm
.endif

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
# let xvid's build system override CFLAGS
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-cflags
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libxvidcore.so

.include <bsd.port.post.mk>
