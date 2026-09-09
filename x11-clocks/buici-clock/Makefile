PORTNAME=	buici-clock
PORTVERSION=	0.4.10
CATEGORIES=	x11-clocks

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Xlib implementation of an attractive, configurable clock
WWW=		https://github.com/rosorio/buici-clock

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcairo.so:graphics/cairo

USES=		autoreconf bison gmake pkgconfig tar:xz xorg
USE_CXXSTD=	c++14
USE_GITHUB=	yes
GH_ACCOUNT=	rosorio
GH_PROJECT=	buici-clock
USE_XORG=	x11 xext

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/buici-clock \
		share/man/man1/buici-clock.1.gz

post-patch:
	@${REINPLACE_CMD} -e \
		's|echo -e|echo| ; \
		s|-g | |' ${WRKSRC}/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/buici-clock ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/buici-clock.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
