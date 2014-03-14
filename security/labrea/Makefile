# Created by: nick@rogness.net
# $FreeBSD$

PORTNAME=	LaBrea
PORTVERSION=	2.4
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://freebsd.rogness.net/ports/labrea/
DISTNAME=	${PORTNAME}${PORTVERSION:S/./_/g}
EXTRACT_SUFX=	.tgz

MAINTAINER=	nick@rogness.net
COMMENT=	Security tarpit defense tool

DEPRECATED=	Unmaintained since 2003
EXPIRATION_DATE=	2014-04-14

BUILD_DEPENDS=	${LIBNET_CONFIG}:${PORTSDIR}/net/libnet10

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet10-config

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e \
		's|libnet-config|${LIBNET_CONFIG}|; \
		 s|--defines|& --cflags|' \
		 ${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/LaBrea ${PREFIX}/bin

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/LaBrea.README ${DOCSDIR}
	@echo "******************************************"
	@echo "You will need to read the LaBrea.README in"
	@echo "${DOCSDIR}"
	@echo "Before your run this!!"
	@echo "******************************************"
	@echo .
.endif

.include <bsd.port.mk>
