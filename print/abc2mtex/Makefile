# New ports collection makefile for:	abc2mtex
# Date created:				28 May 2001
# Whom:					joerg
#
# $FreeBSD$
#

PORTNAME=		abc2mtex
PORTVERSION=		1.6.1
CATEGORIES=		print
MASTER_SITES=		${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	support/abc2mtex
DISTNAME=		${PORTNAME}${PORTVERSION}

MAINTAINER=		joerg@freebsd.org
COMMENT=	Music TeX converter from "abc" to MusiXTeX format

RUN_DEPENDS=		musixtex:${PORTSDIR}/print/musixtex

NO_WRKSUBDIR=		yes

TEXMF=		${PREFIX}/share/texmf
EXAMPLE_FILES=	English.abc Jigs.abc Reels.abc Strspys.abc
DOC_FILES=	usrguide.ps
BIN_FILES=	abc2mtex abc2mtex \
		search abc_search \
		sort_in abc_sort_in

do-install:
	cd ${WRKSRC}; \
	${MKDIR} ${TEXMF}/doc/${PORTNAME}; \
	${INSTALL_DATA} ${DOC_FILES} ${TEXMF}/doc/${PORTNAME}; \
	${MKDIR} ${TEXMF}/doc/${PORTNAME}/examples; \
	${INSTALL_DATA} ${EXAMPLE_FILES} ${TEXMF}/doc/${PORTNAME}/examples; \
	${INSTALL_DATA} header.tex ${TEXMF}/tex/abc2mtex_header.tex
	set -- ${BIN_FILES}; \
	while [ $$# -gt 0 ] ; do \
		src=$$1; tgt=$$2; shift; shift; \
		${ECHO} "Installing $$src as ${PREFIX}/bin/$$tgt"; \
		${INSTALL_PROGRAM} ${WRKSRC}/$$src ${PREFIX}/bin/$$tgt; \
	done

.include <bsd.port.mk>
