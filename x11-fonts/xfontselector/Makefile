# ex:ts=8
# Ports collection makefile for:	xfontselector
# Date created:			May 23, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	xfontselector
PORTVERSION=	0.9.4
CATEGORIES=	x11-fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:R}-4

MAINTAINER=	ports@freebsd.org
COMMENT=	X Font Selector

USE_REINPLACE=	yes
USE_X_PREFIX=	yes
USE_QT_VER=	2
MAKE_ENV=	CXX="${CXX} ${QTCPPFLAGS} -I${X11BASE}/include" \
		LIBS="${QTCFGLIBS} -L${X11BASE}/lib"
ALL_TARGET=	# empty

MAN1=		xfontselector.1
PLIST_FILES=	bin/xfontselector

post-patch:
	@${REINPLACE_CMD} -e "s,^CXX,#CXX,g ; s,^CXXFLAGS,#CXXFLAGS,g ; \
		s,^LIBS=,LIBS+=,g ; s,-lqt,-lqt2,g ; \
		s,moc ,${MOC} ,g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
