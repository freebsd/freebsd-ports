# Created by: Hendrik Scholz <hscholz@raisdorf.net>
# $FreeBSD$

PORTNAME=	buici-clock
PORTVERSION=	0.4.9.4
PORTREVISION=	1
CATEGORIES=	x11-clocks
MASTER_SITES=	DEBIAN
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Xlib implementation of an attractive, configurable clock

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcairo.so:graphics/cairo

WRKSRC=		${WRKDIR}/buici

USES=		tar:xz bison gmake pkgconfig autoreconf xorg
USE_XORG=	x11 xext
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=yes

PLIST_FILES=	bin/buici-clock man/man1/buici-clock.1.gz

post-patch:
	@${REINPLACE_CMD} -e \
		's|echo -e|echo| ; \
		 s|-g | |' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|_=|+=| ; \
		 s|-g | |' ${WRKSRC}/xo/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/buici-clock ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/buici-clock.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
