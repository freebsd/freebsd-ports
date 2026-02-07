PORTNAME=	buici-clock
PORTVERSION=	0.4.9.4
PORTREVISION=	2
CATEGORIES=	x11-clocks
MASTER_SITES=	DEBIAN
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Xlib implementation of an attractive, configurable clock
WWW=		https://packages.qa.debian.org/b/buici-clock.html

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcairo.so:graphics/cairo

USES=		autoreconf bison gmake pkgconfig tar:xz xorg
USE_CXXSTD=	c++14
USE_XORG=	x11 xext

GNU_CONFIGURE=	yes

MAKE_JOBS_UNSAFE=	yes

WRKSRC=		${WRKDIR}/buici

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
