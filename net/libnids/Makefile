# New ports collection makefile for:	libnids
# Date created:		08 Jan 2000
# Whom:			kris@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	libnids
PORTVERSION=	1.20
CATEGORIES=	net security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	roam@FreeBSD.org
COMMENT=	Network monitoring library with TCP/IP reassembly

.if defined(WITH_LIBNET_DEVEL)
BUILD_DEPENDS=	${LOCALBASE}/lib/libnet.a:${PORTSDIR}/net/libnet-devel
.else
BUILD_DEPENDS=	${LOCALBASE}/lib/libnet.a:${PORTSDIR}/net/libnet
.endif

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

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

.include <bsd.port.mk>
