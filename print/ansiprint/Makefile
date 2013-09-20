# Created by: Stephen Fisher
# $FreeBSD$

PORTNAME=		ansiprint
PORTVERSION=		1.0
CATEGORIES=		print
MASTER_SITES=		SF
EXTRACT_SUFX=		.tgz

MAINTAINER=		stephenfisher@outlook.com
COMMENT=		Prints through a terminal with ANSI escape sequences

PLIST_FILES=		bin/${PORTNAME}

CXXFLAGS+=		-Wno-deprecated

NO_STAGE=	yes
post-extract:
	@${RM} ${WRKSRC}/Makefile

do-build:
	cd ${WRKSRC} && ${CXX} ${CXXFLAGS} -o ${PORTNAME} ansiprint.cc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
