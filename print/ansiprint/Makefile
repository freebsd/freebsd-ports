PORTNAME=	ansiprint
PORTVERSION=	1.0
CATEGORIES=	print
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Prints through a terminal with ANSI escape sequences

USES=		tar:tgz
PLIST_FILES=	bin/${PORTNAME}
CXXFLAGS+=	-Wno-deprecated

post-extract:
	@${RM} ${WRKSRC}/Makefile

do-build:
	cd ${WRKSRC} && ${CXX} ${CXXFLAGS} -o ${PORTNAME} ansiprint.cc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
