# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	countrycodes
PORTVERSION=	1.0.5
CATEGORIES=	misc
MASTER_SITES=	http://www.grigna.com/diego/linux/countrycodes/ \
		CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	An ISO 3166 country code finder

LICENSE=	GPLv2

BUILD_WRKSRC=	${WRKSRC}/src
INSTALL_WRKSRC=	${BUILD_WRKSRC}

PLIST_FILES=	bin/iso3166 man/man1/iso3166.1.gz
PORTDOCS=	README

MAKE_ARGS=	prefix="${STAGEDIR}${PREFIX}" CC="${CC}" CCOPTS="${CFLAGS}" WARNINGS=""

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
