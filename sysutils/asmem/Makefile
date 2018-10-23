# Created by: jack
# $FreeBSD$

PORTNAME=	asmem
PORTVERSION=	1.12
PORTREVISION=	1
CATEGORIES=	sysutils afterstep
MASTER_SITES=	http://tigr.net/afterstep/download/asmem/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	AfterStep look-n-feel memory utilization monitor

LICENSE=	GPLv2

BROKEN_FreeBSD_12=	fails to compile: read_mem.c: invalid use of undefined type 'struct vmmeter'
BROKEN_FreeBSD_13=	fails to compile: read_mem.c: invalid use of undefined type 'struct vmmeter'

USE_XORG=	xpm
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-xpm \
		--with-xpm-includes=${LOCALBASE}/include \
		--with-xpm-library=${LOCALBASE}/lib

post-build:
	@${LN} -sf asmem.man ${WRKSRC}/asmem.1

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} asmem \
		${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC} && ${INSTALL_MAN} asmem.1 \
		${STAGEDIR}${MANPREFIX}/man/man1)

.include <bsd.port.mk>
