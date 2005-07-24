# New ports collection makefile for:	countrycodes
# Date created:				6 Jul 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	countrycodes
PORTVERSION=	1.0.5
CATEGORIES=	misc
MASTER_SITES=	http://www.grigna.com/diego/linux/countrycodes/

MAINTAINER=	ehaupt@critical.ch
COMMENT=	An ISO 3166 country code finder

BUILD_WRKSRC=	${WRKSRC}/src
INSTALL_WRKSRC=	${BUILD_WRKSRC}

PLIST_FILES=	bin/iso3166
PORTDOCS=	README
MAN1=		iso3166.1
MAKE_ARGS=	prefix="${PREFIX}" CC="${CC}" CCOPTS="${CFLAGS}" WARNINGS=""

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
