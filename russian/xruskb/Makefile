# Created by: Igor Vinokurov <igor@zynaps.ru>
# $FreeBSD$

PORTNAME=	xruskb
PORTVERSION=	1.15.4
PORTREVISION=	3
CATEGORIES=	russian x11
MASTER_SITES=	ftp://ftp.yars.free.net/pub/source/xruskb/ \
		http://lav.yar.ru/download/xruskb/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Keyboard layout switcher and indicator

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:bzip2 xorg
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datadir=${PREFIX}/share
USE_XORG=	x11 ice xt xmu xext sm

PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	MOTIF DOCS

MOTIF_USES=	motif
MOTIF_CONFIGURE_ON=	--with-toolkit=motif
MOTIF_CONFIGURE_OFF=	--with-toolkit=none

post-install:
	${INSTALL_DATA} ${WRKSRC}/Xrus.ad ${STAGEDIR}${PREFIX}/lib/X11/app-defaults/Xrus

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} FAQ NEWS README* TODO xrus.doc-* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
