# New ports collection makefile for:   	fltk
# Date created:				11 February 1999
# Whom:                			Dima Sivachenko <dima@Chg.RU>
#
# $FreeBSD$
#

PORTNAME=	fltk
PORTVERSION= 	1.0.9
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.fltk.org/pub/fltk/${VERSION}/ \
		ftp://ftp.chg.ru/pub/X11/fltk/${VERSION}/ \
		ftp://ftp2.easysw.com/pub/fltk/${VERSION}/ \
		ftp://ftp.northamerica.net/pub/ESP/fltk/${VERSION}/ \
		ftp://ftp.funet.fi/mirrors/ftp.easysw.com/pub/fltk/${VERSION}/ \
		ftp://ftp.kddlabs.co.jp/pub/lang/fltk/${VERSION}/
DISTNAME=	${PKGNAME}-source

MAINTAINER=	dima@chg.ru

LIB_DEPENDS=	GL.14:${PORTSDIR}/graphics/Mesa3

VERSION=	1.0.9
USE_BZIP2=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-shared
WRKSRC=		${WRKDIR}/${PKGNAME}
USE_X_PREFIX=	yes
MAN1=		fluid.1

post-install:
	@ ${INSTALL_MAN} ${WRKSRC}/documentation/fluid.1 \
		${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/fltk
	for ext in html gif jpg ; do \
		${INSTALL_DATA} ${WRKSRC}/documentation/*.$$ext \
		${PREFIX}/share/doc/fltk; \
	done
	${INSTALL_DATA} ${WRKSRC}/documentation/README \
		${PREFIX}/share/doc/fltk
.endif

.include <bsd.port.mk>
