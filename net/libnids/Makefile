# New ports collection makefile for:	libnids
# Date created:		08 Jan 2000
# Whom:			kris@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	libnids
PORTVERSION=	1.24
CATEGORIES=	net security
MASTER_SITES=	SF

MAINTAINER=	roam@FreeBSD.org
COMMENT=	Network monitoring library with TCP/IP reassembly

LICENSE=	GPLv2

OPTIONS=	LIBNET "Include code requiring libnet" ON \
		LIBNET10 "Use the old libnet-1.0.x version" ON \
		GLIB2 "Use GLIB2 for multiprocessing support" ON

WANT_GNOME=	yes
GNU_CONFIGURE=	yes

MAN3=		libnids.3

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_LIBNET)
.if !defined(WITHOUT_LIBNET10)
BUILD_DEPENDS+=	${LIBNET_CONFIG}:${PORTSDIR}/net/libnet10
LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet10-config
.else
BUILD_DEPENDS+=	${LIBNET_CONFIG}:${PORTSDIR}/net/libnet
LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet11-config
.endif
.else
CONFIGURE_ARGS+=	--disable-libnet
.endif

.if !defined(WITHOUT_GLIB2)
USE_GNOME+=	glib20
.else
CONFIGURE_ARGS+=	--disable-libglib
.endif

post-patch:
	@${REINPLACE_CMD} -Ee \
		's|(LNET_CFLAGS=).*|\1"`${LIBNET_CONFIG} --defines` `${LIBNET_CONFIG} --cflags`"|; \
		 s|(LNETLIB=).*|\1"`${LIBNET_CONFIG} --libs`"|' \
		 ${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

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
