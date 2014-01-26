# Created by: Jacob Rhoden <jacob@dominoid.org>
# $FreeBSD$

PORTNAME=	csv2xml
PORTVERSION=	0.6
CATEGORIES=	textproc
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple but effective csv to xml converter

USE_BZIP2=	yes

PLIST_FILES=	bin/csv2xml man/man1/csv2xml.1.gz
MAKE_ARGS=	FLAGS="${CXXFLAGS}"

post-patch:
	@${REINPLACE_CMD} -e 's/^\(COMPILER[^g]*\)g++$$/\1${CXX}/' \
		${WRKSRC}/src/Makefile \
		${WRKSRC}/man/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/csv2xml ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/man/csv2xml.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
