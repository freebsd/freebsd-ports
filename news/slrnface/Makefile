PORTNAME=	slrnface
PORTVERSION=	2.1.1
PORTREVISION=	7
CATEGORIES=	news
MASTER_SITES=	DEBIAN
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Shows X-Faces from slrn in X11 terminal emulator
WWW=		http://dave.willfork.com/slrnface/

LIB_DEPENDS=	libcompface.so:mail/faces

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
ALL_TARGET=	slrnface
MAKE_ARGS=	CC="${CC}" C_FLAGS="${CFLAGS}" \
		X_INCL=-I${LOCALBASE}/include \
		XF_LIB="-L${LOCALBASE}/lib -lcompface"
USES=		xorg
USE_XORG=	xt

PLIST_FILES=	bin/slrnface share/man/man1/slrnface.1.gz %%DATADIR%%/slrnface.sl

SUB_FILES=	pkg-message

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/slrnface ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/slrnface.1 ${STAGEDIR}${PREFIX}/share/man/man1
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/slrnface.sl ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
