# Created by: Igor Vinokurov <igor@zynaps.ru>
# $FreeBSD$

PORTNAME=	xruskb
PORTVERSION=	1.15.4
PORTREVISION=	2
CATEGORIES=	russian x11
MASTER_SITES=	ftp://ftp.yars.free.net/pub/source/xruskb/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Keyboard layout switcher and indicator

USE_XORG=	x11 ice xt xmu
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datadir=${PREFIX}/share

DOCS=		FAQ NEWS README* TODO xrus.doc-*
PORTDATA=	*

OPTIONS_DEFINE=	MOTIF DOCS

MOTIF_USES=	motif
MOTIF_CONFIGURE_ON=	--with-toolkit=motif
MOTIF_CONFIGURE_OFF=	--with-toolkit=none

post-install:
	${INSTALL_DATA} ${WRKSRC}/Xrus.ad ${STAGEDIR}${PREFIX}/lib/X11/app-defaults/Xrus
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
