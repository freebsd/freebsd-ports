# New ports collection makefile for:   	fltk
# Version required:			19990127
# Date created:				11 February 1999
# Whom:                			Dima Sivachenko <dima@Chg.RU>
#
# $Id: Makefile,v 1.2 1999/03/15 21:26:38 billf Exp $
#

DISTNAME=	fltk-19990127
PKGNAME=	fltk-1999.01.27
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.easysw.com/pub/fltk/ \
		ftp://ftp.northamerica.net/pub/ESP/fltk/ \
		ftp://ftp.funet.fi/mirrors/ftp.easysw.com/pub/fltk/ \
		ftp://ftp.kddlabs.co.jp/pub/lang/fltk/ \
		ftp://ftp.c-com.net/pub/LinuxBerg/files/x11/dev/

MAINTAINER=	dima@chg.ru

LIB_DEPENDS=	MesaGL.14:${PORTSDIR}/graphics/Mesa3

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-shared
USE_X_PREFIX=	yes

post-install:

		@ ${INSTALL_DATA} ${WRKSRC}/lib/libfltk.so.1 ${PREFIX}/lib
		@ ${LDCONFIG} -m
.if !defined(NOPORTDOCS)
		@ ${MKDIR} ${PREFIX}/share/doc/fltk
		@ ${INSTALL_DATA} ${WRKSRC}/documentation/* ${PREFIX}/share/doc/fltk
.endif

.include <bsd.port.mk>
