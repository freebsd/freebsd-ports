# New ports collection makefile for:	libnids
# Date created:		08 Jan 2000
# Whom:			kris@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	libnids
PORTVERSION=	1.21
PORTREVISION=	1
CATEGORIES=	net security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	roam@FreeBSD.org
COMMENT=	Network monitoring library with TCP/IP reassembly

OPTIONS=	LIBNET "Include code requiring libnet" ON \
		LIBNET10 "Use the old libnet-1.0.x version" ON \
		GLIB2 "Use GLIB2 for multiprocessing support" ON

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

MAKE_ENV=	LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_LIBNET)
.if !defined(WITHOUT_LIBNET10)
BUILD_DEPENDS+=	libnet*<=1.1.0,1:${PORTSDIR}/net/libnet10
.else
BUILD_DEPENDS+=	libnet*>=1.1.2,1:${PORTSDIR}/net/libnet
.endif
.else
CONFIGURE_ARGS+=	--disable-libnet
.endif

.if !defined(WITHOUT_GLIB2)
LIB_DEPENDS+=	glib-2.0:${PORTSDIR}/devel/glib20
.else
CONFIGURE_ARGS+=	--disable-libglib
.endif

MAN3=		libnids.3

do-install:
		${INSTALL_DATA} ${WRKSRC}/src/nids.h ${PREFIX}/include
		${INSTALL_DATA} ${WRKSRC}/src/libnids.a ${PREFIX}/lib
		${INSTALL_MAN} ${WRKSRC}/src/libnids.3 ${PREFIX}/man/man3

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in README doc/*
	${INSTALL_DATA} ${WRKSRC}/$i ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.post.mk>
