# Created by: Pavel I Volkov <pavelivolkov@googlemail.com>
# $FreeBSD$

PORTNAME=	ccsrch
PORTVERSION=	1.0.3
CATEGORIES=	security
MASTER_SITES=	http://downloads.sourceforge.net/project/${MASTER_SITE_SUBDIR}/
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTNAME}/Version%20${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pavelivolkov@gmail.com
COMMENT=	Is a tool that searches for credit card numbers (PAN) and track data

LICENSE=	GPLv2

OPTIONS_DEFINE=	DOCS

FETCH_ARGS=	-pRr
NO_STAGE=	yes

PORTDOCS=	README readme.html
PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}; \
	for f in ${PORTDOCS}; do \
		${INSTALL_DATA} ${WRKSRC}/$$f ${DOCSDIR}; \
	done
.endif

.include <bsd.port.mk>
