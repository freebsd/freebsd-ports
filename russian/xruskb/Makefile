# New ports collection makefile for:	xruskb
# Date created:		14 Jan 1998
# Whom:			Igor Vinokurov <igor@zynaps.ru>
#
# $FreeBSD$
#

PORTNAME=	xruskb
PORTVERSION=	1.15.4
PORTREVISION=	2
CATEGORIES=	russian x11
MASTER_SITES=	ftp://ftp.yars.free.net/pub/source/xruskb/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A keyboard layout switcher and indicator

USE_XORG=	x11 ice xt xmu
USE_BZIP2=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--datadir=${PREFIX}/share

MAN1=		xrus.1
DOCS=		FAQ NEWS README* TODO xrus.doc-*

OPTIONS_DEFINE=	MOTIF DOCS
MOTIF_DESC=	Support for pixmaps in indicator icon

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMOTIF}
USE_MOTIF=	yes
CONFIGURE_ARGS+=	--with-toolkit=motif
.else
CONFIGURE_ARGS+=	--with-toolkit=none
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/Xrus.ad ${PREFIX}/lib/X11/app-defaults/Xrus
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
