# Created by: joerg
# $FreeBSD$

PORTNAME=		abc2mtex
PORTVERSION=		1.6.1
CATEGORIES=		print
MASTER_SITES=		TEX_CTAN/support/abc2mtex
DISTNAME=		${PORTNAME}${PORTVERSION}

MAINTAINER=	joerg@FreeBSD.org
COMMENT=	Music TeX converter from "abc" to MusiXTeX format

RUN_DEPENDS=		musixtex:print/musixtex

USE_GCC=	any

NO_WRKSUBDIR=		yes

TEXMF=		${PREFIX}/share/texmf
EXAMPLE_FILES=	English.abc Jigs.abc Reels.abc Strspys.abc
DOC_FILES=	usrguide.ps
BIN_FILES=	abc2mtex abc2mtex \
		search abc_search \
		sort_in abc_sort_in

do-install:
	cd ${WRKSRC}; \
	${MKDIR} ${STAGEDIR}/${TEXMF}/doc/${PORTNAME}; \
	${MKDIR} ${STAGEDIR}/${TEXMF}/tex; \
	${INSTALL_DATA} ${DOC_FILES} ${STAGEDIR}/${TEXMF}/doc/${PORTNAME}; \
	${MKDIR} ${STAGEDIR}/${TEXMF}/doc/${PORTNAME}/examples; \
	${INSTALL_DATA} ${EXAMPLE_FILES} ${STAGEDIR}/${TEXMF}/doc/${PORTNAME}/examples; \
	${INSTALL_DATA} header.tex ${STAGEDIR}/${TEXMF}/tex/abc2mtex_header.tex
	set -- ${BIN_FILES}; \
	while [ $$# -gt 0 ] ; do \
		src=$$1; tgt=$$2; shift; shift; \
		${ECHO} "Installing $$src as ${STAGEDIR}/${PREFIX}/bin/$$tgt"; \
		${INSTALL_PROGRAM} ${WRKSRC}/$$src ${STAGEDIR}/${PREFIX}/bin/$$tgt; \
	done

.include <bsd.port.mk>
