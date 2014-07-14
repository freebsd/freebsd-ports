# Created by: kris@FreeBSD.org
# $FreeBSD$

PORTNAME=	libnids
PORTVERSION=	1.24
PORTREVISION=	2
CATEGORIES=	net security
MASTER_SITES=	SF

MAINTAINER=	wxs@FreeBSD.org
COMMENT?=	Network monitoring library with TCP/IP reassembly

BUILD_DEPENDS=	${LIBNET_CONFIG}:${PORTSDIR}/net/libnet

LICENSE=	GPLv2

CONFLICTS?=	libnids-libnet11-[0-9]*

OPTIONS_DEFINE=	GLIB2
OPTIONS_DEFAULT=GLIB2
GLIB2_DESC=	Use GLIB2 for multiprocessing support
OPTIONS_SUB=	yes

GLIB2_USE=	gnome=glib20
GLIB2_CONFIGURE_ENABLE=	libglib

USES=		pkgconfig
GNU_CONFIGURE=	yes

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet11-config

post-patch:
	@${REINPLACE_CMD} -Ee \
		's|(LNET_CFLAGS=).*|\1"`${LIBNET_CONFIG} --defines` `${LIBNET_CONFIG} --cflags`"|; \
		 s|(LNETLIB=).*|\1"`${LIBNET_CONFIG} --libs`"|' \
		 ${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/nids.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/src/libnids.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_MAN} ${WRKSRC}/src/libnids.3 ${STAGEDIR}${MAN3PREFIX}/man/man3
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} README doc/* ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
