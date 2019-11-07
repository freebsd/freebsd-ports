# Created by: Brian Handy <handy@physics.montana.edu>
# $FreeBSD$

PORTNAME=	astime
PORTVERSION=	2.8
PORTREVISION=	2
CATEGORIES=	x11-clocks afterstep
MASTER_SITES=	AFTERSTEP/apps/astime/ \
		http://tigr.net/afterstep/download/astime/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Time/Date applet for WindowMaker

LICENSE=	GPLv2

USES=		xorg
USE_XORG=	xpm
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-xpm-includes=${LOCALBASE}/include \
		--with-xpm-library=${LOCALBASE}/lib

PLIST_FILES=	bin/astime man/man1/astime.1.gz

post-build:
	@${LN} -sf astime.man ${WRKSRC}/astime.1

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} astime \
		${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC} && ${INSTALL_MAN} astime.1 \
		${STAGEDIR}${MANPREFIX}/man/man1)

.include <bsd.port.mk>
