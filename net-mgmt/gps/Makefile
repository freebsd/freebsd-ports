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

BUILD_DEPENDS=	${LIBNET_CONFIG}:${PORTSDIR}/net/libnet10

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet10-config

NO_STAGE=	yes
.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		's|-Wall -O3|${CFLAGS}|; \
		 s|-lnet|`${LIBNET_CONFIG} --libs`|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e \
		's|libnet-config|${LIBNET_CONFIG}|; \
		 s|--defines|& --cflags|' \
		${WRKSRC}/Makefile.in

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	${CP} ${WRKSRC}/docs/* ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
