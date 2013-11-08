# Created by: jack
# $FreeBSD$

PORTNAME=	asmem
PORTVERSION=	1.12
PORTREVISION=	1
CATEGORIES=	sysutils afterstep
MASTER_SITES=	http://www.tigr.net/afterstep/download/asmem/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An AfterStep look-n-feel memory utilization monitor

USE_XORG=	xpm
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-xpm \
		--with-xpm-includes=${LOCALBASE}/include \
		--with-xpm-library=${LOCALBASE}/lib

PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz

do-install:
	${INSTALL_PROGRAM} -g kmem -m 2755 ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.man ${STAGEDIR}${PREFIX}/man/man1/${PORTNAME}.1

.include <bsd.port.mk>
