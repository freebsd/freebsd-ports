# New ports collection makefile for:	gpac-libm4systems
# Date created:		2005-05-04
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gpac
PORTVERSION=	0.4.5
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}/GPAC/GPAC%20${PORTVERSION}
PKGNAMESUFFIX=	-libgpac

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Gpac MPEG-4 Systems library and headers

WRKSRC=		${WRKDIR}/gpac
ALL_TARGET=	lib
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes
HAS_CONFIGURE=	yes
USE_LDCONFIG=	yes

BUILD_WRKSRC=	${WRKSRC}/src
INSTALL_WRKSRC=	${WRKSRC}/bin/gcc
LIBVER=	1

OPTIONS=	IPV6	"IPv6 support"		on \
		OPENGL	"OpenGL support"	on

CONFIGURE_ARGS=	--cc="${CC}" --X11-path="${X11BASE}" \
		--extra-cflags="${CFLAGS}" --extra-ldflags="${LDFLAGS}" \
		--enable-pic
CONFIGURE_ENV+=	LIBVER="${LIBVER}" PTHREAD_LIBS="${PTHREAD_LIBS}"

.include <bsd.port.pre.mk>

.if defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if defined(WITHOUT_OPENGL)
CONFIGURE_ARGS+=	--disable-opengl
.else
USE_GL=		gl glu
.endif

post-patch:
	${CHMOD} +x ${WRKSRC}/configure

do-install:
	${MKDIR} ${PREFIX}/include/gpac
	cd ${WRKSRC}/include/gpac && ${FIND} . | \
		${CPIO} -vpdm -L -R ${LIBOWN}:${LIBGRP} ${PREFIX}/include/gpac
	${INSTALL_DATA} ${INSTALL_WRKSRC}/libgpac.so.${LIBVER} ${PREFIX}/lib
	${LN} -sf libgpac.so.${LIBVER} ${PREFIX}/lib/libgpac.so
	${INSTALL_DATA} ${INSTALL_WRKSRC}/libgpac_static.a ${PREFIX}/lib

.include <bsd.port.post.mk>
