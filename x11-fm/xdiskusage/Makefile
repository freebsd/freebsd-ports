# New ports collection makefile for:	xdiskusage
# Date created:				2000-09-23
# Whom:					Trevor Johnson
#
# $FreeBSD$
#

PORTNAME=	xdiskusage
PORTVERSION=	1.48
PORTREVISION=	6
CATEGORIES=	x11-fm
MASTER_SITES=	http://xdiskusage.sourceforge.net/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Show where disk space is taken up

LIB_DEPENDS=	fltk.1:${PORTSDIR}/x11-toolkits/fltk

USE_GMAKE=	yes

PLIST_FILES=	bin/xdiskusage
MAN1=		xdiskusage.1

post-patch:
	${REINPLACE_CMD} -e '22,24d' ${WRKSRC}/Makefile

do-build:
	cd ${WRKSRC} && ${GMAKE} CXXFLAGS="`fltk-config --cxxflags`" LDFLAGS="`fltk-config --ldflags`"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xdiskusage ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xdiskusage.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
