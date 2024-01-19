PORTNAME=	pspresent
PORTVERSION=	1.3
PORTREVISION=	8
CATEGORIES=	misc
MASTER_SITES=	http://www.zmatt.net/pspresent/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Full-screen slide shows of postscript files
WWW=		http://www.zmatt.net/pspresent/

LICENSE=	GPLv2

USES=		ghostscript:x11,run xorg
USE_XORG=	x11 xext xinerama
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" LDLIBS="${LDFLAGS}"
ALL_TARGET=	pspresent

PLIST_FILES=	bin/pspresent share/man/man1/pspresent.1.gz

CFLAGS+=	-I${LOCALBASE}/include -DHAVE_LIBXINERAMA
LDFLAGS+=	-L${LOCALBASE}/lib -lX11 -lXext -lXinerama

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pspresent ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pspresent.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
