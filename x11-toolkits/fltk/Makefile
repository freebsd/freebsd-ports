# New ports collection makefile for:   	fltk
# Version required:			1.0.1
# Date created:				11 February 1999
# Whom:                			Dima Sivachenko <dima@Chg.RU>
#
# $Id: Makefile,v 1.3 1999/04/09 19:26:49 billf Exp $
#

DISTNAME=	fltk-1.0.1-source
PKGNAME=	fltk-1.0.1
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.fltk.org/pub/fltk/${VERSION}/ \
		ftp://ftp.easysw.com/pub/fltk/${VERSION}/ \
		ftp://ftp2.easysw.com/pub/fltk/${VERSION}/ \
		ftp://ftp.northamerica.net/pub/ESP/fltk/${VERSION}/ \
		ftp://ftp.funet.fi/mirrors/ftp.easysw.com/pub/fltk/${VERSION}/ \
		ftp://ftp.kddlabs.co.jp/pub/lang/fltk/${VERSION}/

MAINTAINER=	dima@chg.ru

LIB_DEPENDS=	MesaGL.14:${PORTSDIR}/graphics/Mesa3

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ENV=	CXXFLAGS="${CFLAGS}"
WRKSRC=	${WRKDIR}/${PKGNAME}
USE_X_PREFIX=	yes
MAN1=	fluid.1
VERSION=	1.0.1

.if defined(NOPORTDOCS)
PLIST=	${PKGDIR}/PLIST.nodocs
.endif

post-install:
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib
	${INSTALL_MAN} ${WRKSRC}/documentation/fluid.1 \
		${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/fltk
	@ ${INSTALL_DATA} ${WRKSRC}/documentation/*.html \
		 ${PREFIX}/share/doc/fltk
	@ ${INSTALL_DATA} ${WRKSRC}/documentation/*.gif \
		${PREFIX}/share/doc/fltk
	@ ${INSTALL_DATA} ${WRKSRC}/documentation/*.jpg \
		${PREFIX}/share/doc/fltk
.endif

.include <bsd.port.mk>
