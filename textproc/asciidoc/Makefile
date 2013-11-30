# Created by: anholt@FreeBSD.org
# $FreeBSD$

PORTNAME=	asciidoc
PORTVERSION=	8.6.9
CATEGORIES=	textproc
MASTER_SITES=	SF

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Text document format for writing short documents and man pages

LICENSE=	GPLv2 MIT
LICENSE_COMB=	multi

RUN_DEPENDS=	python2:${PORTSDIR}/lang/python2

OPTIONS_DEFINE=	VIM
OPTIONS_DEFAULT=VIM
OPTIONS_SUB=	yes
VIM_DESC=	Install Vim syntax file

GNU_CONFIGURE=	yes
USE_PYTHON=	-2.7
USES=		gmake

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

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MVIM}
PLIST_SUB+=	VIM_DATADIR=${VIM_DATADIR}
VIM_DATADIR!=	${MAKE} -C ../../editors/vim/ -V _DATADIR
.else
PLIST_SUB+=	VIM_DATADIR=""
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^INSTALL_PROG/ s|INSTALL_PROGRAM|INSTALL_SCRIPT|; s|\.conf|&.sample|' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|${SETENV} python|&2|' ${WRKSRC}/a2x.py ${WRKSRC}/asciidoc.py
.for conf_file in ${CONF_FILES}
	@cd ${WRKSRC}/ && ${MV} ${conf_file} ${conf_file}.sample
.endfor

post-install:
.for conf_file in ${CONF_FILES}
	@if [ ! -f ${ETCDIR}/${conf_file} ]; then \
		${CP} -p ${STAGEDIR}${ETCDIR}/${conf_file}.sample ${STAGEDIR}${ETCDIR}/${conf_file}; \
	fi
.endfor
.if ${PORT_OPTIONS:MVIM}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/vim/${VIM_DATADIR}/syntax/
	${INSTALL_DATA} ${WRKSRC}/vim/syntax/asciidoc.vim ${STAGEDIR}${PREFIX}/share/vim/${VIM_DATADIR}/syntax/
.endif

.include <bsd.port.mk>
