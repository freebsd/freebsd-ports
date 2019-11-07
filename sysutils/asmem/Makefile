# Created by: jack
# $FreeBSD$

PORTNAME=	asmem
PORTVERSION=	1.12
PORTREVISION=	1
CATEGORIES=	sysutils afterstep
MASTER_SITES=	https://tigr.net/afterstep/download/asmem/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	AfterStep look-n-feel memory utilization monitor

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		xorg
USE_XORG=	x11 ice sm x11 xext xpm

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-xpm \
		--with-xpm-includes=${LOCALBASE}/include \
		--with-xpm-library=${LOCALBASE}/lib

post-build:
	@${LN} -sf asmem.man ${WRKSRC}/asmem.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/asmem ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/asmem.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
