# Created by: lofi@FreeBSD.org
# $FreeBSD$

PORTNAME=	libpaper
PORTVERSION=	1.1.24
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_DEBIAN}
MASTER_SITE_SUBDIR=	pool/main/libp/libpaper
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	A library providing routines for paper size management

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

pre-configure:
	@${TOUCH} ${WRKSRC}/config.sub
	@${REINPLACE_CMD} -E -e 's|(#!).*/bin/bash|\1/bin/sh|g' \
			-e 's|==|=|g' \
		${WRKSRC}/src/paperconfig.in

post-configure:
	@${REINPLACE_CMD} -e 's|$${prefix}|${PREFIX}|g' ${WRKSRC}/config.h \
			${WRKSRC}/src/paperconfig

pre-build:
	${ECHO_CMD} a4 > ${WRKDIR}/papersize.a4
	${ECHO_CMD} letter > ${WRKDIR}/papersize.letter

post-install:
	cd ${WRKDIR} && \
		${INSTALL_DATA} papersize.a4 papersize.letter ${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
