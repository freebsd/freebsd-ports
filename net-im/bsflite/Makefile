# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	bsflite
DISTVERSION=	0.85
CATEGORIES=	net-im
MASTER_SITES=	SF

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Lightweight command line AIM client

PLIST_FILES=	bin/bsflite %%EXAMPLESDIR%%/config-example
PLIST_DIRS=	%%EXAMPLESDIR%%
PORTDOCS=	COPYING ChangeLog README

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -E '/^(CC|CFLAGS)/d' \
		${WRKSRC}/${MAKEFILE} \
		${WRKSRC}/imcomm/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bsflite ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/config-example ${STAGEDIR}${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
