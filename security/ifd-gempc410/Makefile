# New ports collection makefile for:	ifd-gempc410
# Date created:		2003-05-09
# Whom:			des
#
# $FreeBSD$
#

PORTNAME=	ifd-gempc410
PORTVERSION=	0.8.0
CATEGORIES=	security
MASTER_SITES=	http://ludovic.rousseau.free.fr/softwares/ifd-GemPC/
DISTNAME=	ifd-gempc-${PORTVERSION}

MAINTAINER=	des@freebsd.org
COMMENT=	PC/SC Lite driver for the GemPC 410 serial smart card reader

BUILD_DEPENDS=	${LOCALBASE}/include/ifdhandler.h:${PORTSDIR}/security/ifd-devkit
LIB_DEPENDS=	pcsclite.0:${PORTSDIR}/devel/pcsc-lite

USE_GMAKE=	yes

MAKE_ENV+=	DESTDIR="${PREFIX}"
MAKE_ARGS+=	-CGemPC410

INSTALLS_SHLIB=	yes

NOMAN=

PKGMESSAGE=	${WRKDIR}/message

post-configure:
	${SED} -e 's|%%PREFIX%%|${PREFIX}|g' <${FILESDIR}/message >${PKGMESSAGE}
	${TOUCH} ${WRKSRC}/GemPC410/dep_stamp ${WRKSRC}/common/dep_stamp

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
