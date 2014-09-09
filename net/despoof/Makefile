# Created by: Kris Kennaway <kris@FreeBSD.org>
# $FreeBSD$

PORTNAME=	despoof
PORTVERSION=	0.9
PORTREVISION=	3
CATEGORIES=	net security
MASTER_SITES=	${MASTER_SITE_PACKETSTORM}
MASTER_SITE_SUBDIR=	UNIX/misc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command-line anti-spoofing detection utility

DEPRECATED=	Depends on expired net/libnet10
EXPIRATION_DATE=	2014-09-30

BUILD_DEPENDS=	${LIBNET_CONFIG}:${PORTSDIR}/net/libnet10

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet10-config
USES=		tar:tgz

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		's|-I$${LOCALBASE}/include ||; \
		 s|-L$${LOCALBASE}/lib ||; \
		 s|--defines|& --cflags|; \
		 s|libnet-config|${LIBNET_CONFIG}|; \
		 s|-lnet |`${LIBNET_CONFIG} --libs` |' \
		 ${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/despoof ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
