# Created by: Jacob Rhoden <jacob@dominoid.org>
# $FreeBSD$

PORTNAME=	csv2xml
PORTVERSION=	0.6
CATEGORIES=	textproc
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple but effective csv to xml converter

USE_BZIP2=	yes

MAN1=		csv2xml.1
MANCOMPRESSED=	yes
PLIST_FILES=	bin/csv2xml
MAKE_ARGS=	FLAGS="${CXXFLAGS}"

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's,/usr/local,${PREFIX},g' \
		-e 's/^\(COMPILER[^g]*\)g++$$/\1${CXX}/' \
		${WRKSRC}/src/Makefile \
		${WRKSRC}/man/Makefile

.include <bsd.port.mk>
