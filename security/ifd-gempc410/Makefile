# New ports collection makefile for:	ifd-gempc410
# Date created:		2003-05-09
# Whom:			des
#
# $FreeBSD$
#

PORTNAME=	ifd-gempc410
PORTVERSION=	0.9.3
CATEGORIES=	security
MASTER_SITES=	http://ludovic.rousseau.free.fr/softwares/ifd-GemPC/
DISTNAME=	ifd-gempc-${PORTVERSION}

MAINTAINER=	des@freebsd.org
COMMENT=	PC/SC Lite driver for the GemPC 410 serial smart card reader

BUILD_DEPENDS=	${LOCALBASE}/include/ifdhandler.h:${PORTSDIR}/security/ifd-devkit
LIB_DEPENDS=	pcsclite.1:${PORTSDIR}/devel/pcsc-lite

USE_GMAKE=	yes

MAKE_ARGS+=	-CGemPC410

INSTALLS_SHLIB=	yes

NOMAN=

PKGMESSAGE=	${WRKDIR}/message

post-configure:
	${FIND} ${WRKSRC} -type f -print0 | ${XARGS} -0 ${REINPLACE_CMD} \
		-e '/INCS/ s,/usr/local,${LOCALBASE},g' \
		-e '/DESTDIR/ s,/usr/local,${PREFIX},g'
	${SED} -e 's|%%PREFIX%%|${PREFIX}|g' <${FILESDIR}/message >${PKGMESSAGE}
	${TOUCH} ${WRKSRC}/GemPC410/dep_stamp ${WRKSRC}/common/dep_stamp

do-install:
	${MKDIR} ${PREFIX}/lib/pcsc/drivers/serial
	${INSTALL_DATA} ${WRKSRC}/GemPC410/libGemPC410.so* \
		${PREFIX}/lib/pcsc/drivers/serial

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
