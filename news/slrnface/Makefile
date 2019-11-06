# Created by: Oliver Braun <obraun@informatik.unibw-muenchen.de>
# $FreeBSD$

PORTNAME=	slrnface
PORTVERSION=	2.1.1
PORTREVISION=	6
CATEGORIES=	news
MASTER_SITES=	DEBIAN
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Shows X-Faces from slrn in X11 terminal emulator

LIB_DEPENDS=	libcompface.so:mail/faces

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
ALL_TARGET=	slrnface
MAKE_ARGS=	CC="${CC}" C_FLAGS="${CFLAGS}" \
		X_INCL=-I${LOCALBASE}/include \
		XF_LIB="-L${LOCALBASE}/lib -lcompface"
USES=		xorg
USE_XORG=	xt

PLIST_FILES=	bin/slrnface man/man1/slrnface.1.gz %%DATADIR%%/slrnface.sl

SUB_FILES=	pkg-message

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/slrnface ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/slrnface.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/slrnface.sl ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
