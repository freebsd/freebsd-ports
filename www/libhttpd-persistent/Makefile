# New ports collection makefile for:	libhttpd-persistent
# Date created:				19 October 2003
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$
#

PORTNAME=	libhttpd
PORTVERSION=	${VERSION}${LEVEL}
PORTREVISION=	1
CATEGORIES=	www devel
MASTER_SITES=	http://www.deleet.de/projekte/daap/daapd/
PKGNAMESUFFIX=	-persistent
DISTNAME=	${PORTNAME}-${VERSION}p-${LEVEL}
EXTRACT_SUFX=	.tgz

MAINTAINER=	lars@thegler.dk
COMMENT=	Library for embedded web servers

WRKSRC=		${WRKDIR}/${PORTNAME}-${VERSION}-persistent-${LEVEL}
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
CC=		${CXX}

VERSION=	1.3
LEVEL=		f

DOCS=		README HISTORY License doc/FAQ.txt doc/libhttpd.pdf

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' \
		${WRKSRC}/Site.mm.in \
		${WRKSRC}/src/Makefile.tmpl

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
