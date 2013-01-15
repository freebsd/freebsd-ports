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

MAKE_JOBS_SAFE=	yes

PLIST_FILES=	bin/iso3166
PORTDOCS=	README
MAN1=		iso3166.1

MAKE_ARGS=	prefix="${PREFIX}" CC="${CC}" CCOPTS="${CFLAGS}" WARNINGS=""

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
