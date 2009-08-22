# New ports collection makefile for:   ansiprint
# Date created:				28 May 2006
# Whom:					stephentfisher@yahoo.com
#
# $FreeBSD$
#

PORTNAME=		ansiprint
PORTVERSION=		1.0
CATEGORIES=		print
MASTER_SITES=		SF
DISTNAME=		${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=		.tgz

MAINTAINER=		stephentfisher@yahoo.com
COMMENT=		Prints through a terminal with ANSI escape sequences

PLIST_FILES=		bin/${PORTNAME}

CXXFLAGS+=		-Wno-deprecated

post-extract:
	@${RM} ${WRKSRC}/Makefile

do-build:
	cd ${WRKSRC} && ${CXX} ${CXXFLAGS} -o ${PORTNAME} ansiprint.cc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
