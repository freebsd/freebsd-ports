# Created by: kris@FreeBSD.org
# $FreeBSD$

PORTNAME=	libnids
PORTVERSION=	1.24
PORTREVISION=	3
CATEGORIES=	net security
MASTER_SITES=	SF

MAINTAINER=	wxs@FreeBSD.org
COMMENT?=	Network monitoring library with TCP/IP reassembly

LIB_DEPENDS=	libnet.so:net/libnet

LICENSE=	GPLv2

OPTIONS_DEFINE=	GLIB2 DOCS
OPTIONS_DEFAULT=GLIB2
GLIB2_DESC=	Use GLIB2 for multiprocessing support
OPTIONS_SUB=	yes

GLIB2_USE=	gnome=glib20
GLIB2_CONFIGURE_ENABLE=	libglib

USES=		pkgconfig
GNU_CONFIGURE=	yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/nids.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/src/libnids.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_MAN} ${WRKSRC}/src/libnids.3 ${STAGEDIR}${MAN3PREFIX}/man/man3
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} README doc/* ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
