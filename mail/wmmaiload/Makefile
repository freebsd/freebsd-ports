PORTNAME=	wmmaiload
PORTVERSION=	2.3.0
PORTREVISION=	2
CATEGORIES=	mail windowmaker
MASTER_SITES=	http://tnemeth.free.fr/projets/programmes/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Incoming mail monitor dockapp with a similar look to wmcpuload
WWW=		http://tnemeth.free.fr/projets/dockapps.html

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		gmake gnome localbase:ldflags pkgconfig ssl tar:bzip2 xorg
USE_XORG=	x11 xext xpm
USE_GNOME=	cairo gdkpixbuf2 gtk20
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}
CFLAGS+=	-fcommon
CPPFLAGS+=	-I${OPENSSLINC} -D_GNU_SOURCE
LDFLAGS+=	-L${OPENSSLLIB}
MAKE_ENV=	DEBUG_CFLAGS="" DEBUG_LDFLAGS=""

PLIST_FILES=	bin/wmmaiload bin/wmmaiload-config \
		share/man/man1/wmmaiload.1.gz \
		share/man/man1/wmmaiload-config.1.gz

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile" | ${XARGS} ${REINPLACE_CMD} -e \
		's| =| ?=|'

do-install:
.for i in wmmaiload wmmaiload-config
	${INSTALL_PROGRAM} ${WRKSRC}/${i}/${i} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/${i}.1 ${STAGEDIR}${PREFIX}/share/man/man1
.endfor

.include <bsd.port.mk>
