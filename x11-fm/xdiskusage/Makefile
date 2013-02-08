# Created by: trevor
# $FreeBSD$

PORTNAME=	xdiskusage
PORTVERSION=	1.48
PORTREVISION=	7
CATEGORIES=	x11-fm
MASTER_SITES=	http://xdiskusage.sourceforge.net/ \
		http://www.gnu-darwin.org/distfiles/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Show where disk space is taken up

LIB_DEPENDS=	fltk.1:${PORTSDIR}/x11-toolkits/fltk

USE_GMAKE=	yes

CXXFLAGS+=	`fltk-config --cxxflags`
LDFLAGS+=	`fltk-config --ldflags`

PLIST_FILES=	bin/xdiskusage
MAN1=		xdiskusage.1

post-patch:
	${REINPLACE_CMD} -e '22,24d' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xdiskusage ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xdiskusage.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
