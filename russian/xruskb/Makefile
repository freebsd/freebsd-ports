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
USE_BZIP2=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--datadir=${PREFIX}/share

MAN1=		xrus.1
DOCS=		FAQ NEWS README* TODO xrus.doc-*

OPTIONS_DEFINE=	MOTIF DOCS
MOTIF_DESC=	Support for pixmaps in indicator icon

MOTIF_USES=	motif
MOTIF_CONFIGURE_ON=	--with-toolkit=motif
MOTIF_CONFIGURE_OFF=	--with-toolkit=none

.include <bsd.port.options.mk>

post-install:
	${INSTALL_DATA} ${WRKSRC}/Xrus.ad ${PREFIX}/lib/X11/app-defaults/Xrus
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
