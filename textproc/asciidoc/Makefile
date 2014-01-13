# Created by: anholt@FreeBSD.org
# $FreeBSD$

PORTNAME=	asciidoc
PORTVERSION=	8.6.9
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	SF

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Text document format for writing short documents and man pages

LICENSE=	GPLv2 MIT
LICENSE_COMB=	multi

RUN_DEPENDS=	python2:${PORTSDIR}/lang/python2

GNU_CONFIGURE=	yes
USE_PYTHON=	2
USES=		gmake shebangfix

CONF_FILES=	asciidoc.conf docbook45.conf filters/code/code-filter.conf \
		filters/graphviz/graphviz-filter.conf \
		filters/latex/latex-filter.conf \
		filters/music/music-filter.conf \
		filters/source/source-highlight-filter.conf help.conf \
		html4.conf html5.conf lang-cs.conf lang-de.conf lang-el.conf \
		lang-en.conf lang-es.conf lang-fr.conf lang-hu.conf \
		lang-it.conf lang-nl.conf lang-pt-BR.conf lang-ro.conf \
		lang-ru.conf lang-uk.conf latex.conf slidy.conf text.conf \
		xhtml11.conf xhtml11-quirks.conf

SHEBANG_FILES=	a2x.py \
		asciidoc.py \
		asciidocapi.py \
		filters/latex/latex2png.py \
		filters/graphviz/graphviz2png.py \
		filters/music/music2png.py \
		filters/code/code-filter.py
python_OLD_CMD=	${SETENV} python
python_CMD=	${PYTHON_CMD}

post-patch:
	@${REINPLACE_CMD} -e '/^INSTALL_PROG/ s|INSTALL_PROGRAM|INSTALL_SCRIPT|; s|\.conf|&.sample|' ${WRKSRC}/Makefile.in
.for conf_file in ${CONF_FILES}
	@cd ${WRKSRC}/ && ${MV} ${conf_file} ${conf_file}.sample
.endfor

post-install:
	${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/
	${INSTALL_DATA} ${WRKSRC}/asciidocapi.py ${STAGEDIR}${PYTHON_SITELIBDIR}/
.for conf_file in ${CONF_FILES}
	@if [ ! -f ${ETCDIR}/${conf_file} ]; then \
		${CP} -p ${STAGEDIR}${ETCDIR}/${conf_file}.sample ${STAGEDIR}${ETCDIR}/${conf_file}; \
	fi
.endfor

.include <bsd.port.mk>
