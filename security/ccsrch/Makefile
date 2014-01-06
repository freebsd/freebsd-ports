# Created by: Pavel I Volkov <pavelivolkov@googlemail.com>
# $FreeBSD$

PORTNAME=	ccsrch
PORTVERSION=	1.0.3
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://downloads.sourceforge.net/project/${MASTER_SITE_SUBDIR}/
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTNAME}/Version%20${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pavelivolkov@gmail.com
COMMENT=	Is a tool that searches for credit card numbers (PAN) and track data

LICENSE=	GPLv2

OPTIONS_DEFINE=	DOCS

PORTDOCS=	README
PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}; \
	for f in ${PORTDOCS}; do \
		${INSTALL_DATA} ${WRKSRC}/$$f ${STAGEDIR}${DOCSDIR}; \
	done
.endif

.include <bsd.port.mk>
