# Created by: dikshie@sfc.wide.ad.jp
# $FreeBSD$

PORTNAME=	iffinder
PORTVERSION=	1.38
CATEGORIES=	net
MASTER_SITES=	http://www.caida.org/tools/measurement/iffinder/download/

MAINTAINER=	dikshie@sfc.wide.ad.jp
COMMENT=	Tools for find other interfaces for same router

LICENSE=	BSD2CLAUSE

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/iffinder
PORTDOCS=	README

.include <bsd.port.options.mk>
.if ${OSVERSION} < 1000100
@${REINPLACE_CMD} -e 's|CC=gcc|CC=clang|g' ${WRKSRC}/Makefile.in
.endif

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/iffinder ${STAGEDIR}${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
