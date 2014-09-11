# Created by: ijliao
# $FreeBSD$

PORTNAME=	gps
PORTVERSION=	0.9.3
PORTREVISION=	4
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.bsd-geek.de/FreeBSD/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION}-FRC

MAINTAINER=	lme@FreeBSD.org
COMMENT=	Ghost Port Scan

LICENSE=	GPLv2

DEPRECATED=	Depends on expired net/libnet10
EXPIRATION_DATE=	2014-09-30

BUILD_DEPENDS=	${LIBNET_CONFIG}:${PORTSDIR}/net/libnet10

GNU_CONFIGURE=	yes
USES=		gmake

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet10-config

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		's|-Wall -O3|${CFLAGS}|; \
		 s|-lnet|`${LIBNET_CONFIG} --libs`|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e \
		's|libnet-config|${LIBNET_CONFIG}|; \
		 s|--defines|& --cflags|' \
		${WRKSRC}/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CP} ${WRKSRC}/docs/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
