# Created by: Vaida Bogdan <vaida.bogdan@gmail.com>
# $FreeBSD$

PORTNAME=	manipulate_data
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	PACKETSTORM/groups/thc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Search/extract/write raw data

SBIN_PROGRAMS=	read_data replace_data search_data write_data

PORTDOCS=	CHANGES README
PLIST_FILES=	${SBIN_PROGRAMS:S,^,sbin/,}

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		's|^CC=|CC?=| ; \
		s| -O2 | $$(CFLAGS) | ; \
		/strip/s|^|#|' ${WRKSRC}/Makefile

do-install:
.for i in ${SBIN_PROGRAMS}
	${INSTALL_PROGRAM} ${WRKSRC}/${i} ${STAGEDIR}${PREFIX}/sbin
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
