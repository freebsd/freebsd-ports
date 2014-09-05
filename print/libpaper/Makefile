# Created by: lofi@FreeBSD.org
# $FreeBSD$

PORTNAME=	libpaper
PORTVERSION=	1.1.24.3
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_DEBIAN}
MASTER_SITE_SUBDIR=	pool/main/libp/libpaper
DISTNAME=	${PORTNAME}_${PORTVERSION:C/.([0-9]+)$/+nmu\1/}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Library providing routines for paper size management

LICENSE=	GPLv2

USES=		libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:C/.([0-9]+)$/+nmu\1/}
INSTALL_TARGET=	install-strip

post-extract:
	${ECHO_CMD} a4 > ${WRKDIR}/papersize.a4
	${ECHO_CMD} letter > ${WRKDIR}/papersize.letter

post-configure:
	@${REINPLACE_CMD} -e 's|$${prefix}|${PREFIX}|g' \
	    ${WRKSRC}/config.h ${WRKSRC}/src/paperconfig

post-install:
	cd ${WRKDIR} && \
	    ${INSTALL_DATA} papersize.a4 papersize.letter \
	    ${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
