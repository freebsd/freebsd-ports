# New ports collection makefile for:	xruskb
# Date created:		14 Jan 1998
# Whom:			Igor Vinokurov <igor@zynaps.ru>
#
# $FreeBSD$
#

PORTNAME=	xruskb
PORTVERSION=	1.15.2
CATEGORIES=	russian x11
MASTER_SITES=	ftp://ftp.yars.free.net/pub/software/unix/X11/

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	A keyboard layout switcher and indicator

USE_X_PREFIX=	YES

GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--datadir=${PREFIX}/share

MAN1=		xrus.1

post-install:
	${INSTALL_DATA} ${WRKSRC}/Xrus.ad ${PREFIX}/lib/X11/app-defaults/Xrus
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/xruskb
	${INSTALL_DATA} ${WRKSRC}/xrus.doc-english ${PREFIX}/share/doc/xruskb
	${INSTALL_DATA} ${WRKSRC}/xrus.doc-koi8 ${PREFIX}/share/doc/xruskb
.endif

.include <bsd.port.mk>
