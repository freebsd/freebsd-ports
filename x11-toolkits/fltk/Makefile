# New ports collection makefile for:   	fltk
# Version required:			1.0.2
# Date created:				11 February 1999
# Whom:                			Dima Sivachenko <dima@Chg.RU>
#
# $FreeBSD$
#

DISTNAME=	fltk-1.0.3-source
PKGNAME=	fltk-1.0.3
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.fltk.org/pub/fltk/${VERSION}/ \
		ftp://ftp.chg.ru/pub/X11/fltk/${VERSION}/ \
		ftp://ftp2.easysw.com/pub/fltk/${VERSION}/ \
		ftp://ftp.northamerica.net/pub/ESP/fltk/${VERSION}/ \
		ftp://ftp.funet.fi/mirrors/ftp.easysw.com/pub/fltk/${VERSION}/ \
		ftp://ftp.kddlabs.co.jp/pub/lang/fltk/${VERSION}/

MAINTAINER=	dima@chg.ru

LIB_DEPENDS=	MesaGL.14:${PORTSDIR}/graphics/Mesa3

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-shared
WRKSRC=		${WRKDIR}/${PKGNAME}
USE_X_PREFIX=	yes
MAN1=		fluid.1
VERSION=	1.0.3

.include <bsd.port.pre.mk>
.if (${PORTOBJFORMAT} == "aout")
BROKEN=	requires ELF library format
.endif

post-install:
	@ ${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib
	@ ${INSTALL_MAN} ${WRKSRC}/documentation/fluid.1 \
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

.include <bsd.port.post.mk>
