# Created by: Kris Kennaway <kris@FreeBSD.org>
# $FreeBSD$

PORTNAME=	despoof
PORTVERSION=	0.9
PORTREVISION=	3
CATEGORIES=	net security
MASTER_SITES=	${MASTER_SITE_PACKETSTORM}
MASTER_SITE_SUBDIR=	UNIX/misc
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command-line anti-spoofing detection utility

BUILD_DEPENDS=	${LIBNET_CONFIG}:${PORTSDIR}/net/libnet10

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet10-config

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e \
		's|-I$${LOCALBASE}/include ||; \
		 s|-L$${LOCALBASE}/lib ||; \
		 s|--defines|& --cflags|; \
		 s|libnet-config|${LIBNET_CONFIG}|; \
		 s|-lnet |`${LIBNET_CONFIG} --libs` |' \
		 ${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/despoof ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
