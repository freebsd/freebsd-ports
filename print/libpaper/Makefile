# Created by: lofi@FreeBSD.org

PORTNAME=	libpaper
DISTVERSION=	1.1.28
CATEGORIES=	print
MASTER_SITES=	DEBIAN
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Library providing routines for paper size management

LICENSE=	GPLv2

USES=		autoreconf libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

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
