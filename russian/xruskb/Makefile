# New ports collection makefile for:	xruskb
# Version required:	1.7.0
# Date created:		14 Jan 1998
# Whom:			Igor Vinokurov <igor@zynaps.ru>
#
# $Id$

DISTNAME=	xruskb-1.7.0
CATEGORIES=	russian x11
MASTER_SITES=	ftp://ftp.kiae.su/pub/x11/cyrillic/ \
		ftp://ftp.yars.free.net/pub/software/unix/X11/

MAINTAINER=	igor@zynaps.ru

USE_X_PREFIX=	yes

GNU_CONFIGURE=	Yes
CONFIGURE_ARGS=	--datadir=${PREFIX}/share/examples

MAN1=		xrus.1

post-install:
	${INSTALL_DATA} ${WRKSRC}/Xrus.ad ${PREFIX}/lib/X11/app-defaults/Xrus
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/xruskb
	${INSTALL_DATA} ${WRKSRC}/xrus.doc-english ${PREFIX}/share/doc/xruskb
	${INSTALL_DATA} ${WRKSRC}/xrus.doc-koi8 ${PREFIX}/share/doc/xruskb
.endif

.include <bsd.port.mk>
