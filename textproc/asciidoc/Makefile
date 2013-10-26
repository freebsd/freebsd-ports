# Created by: anholt@FreeBSD.org
# $FreeBSD$

PORTNAME=	asciidoc
PORTVERSION=	8.6.8
PORTREVISION=	1
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
VIM_DESC=	Install Vim ftdetect & syntax files

GNU_CONFIGURE=	yes
USE_PYTHON=	-2.7
USES=		gmake

CONF_FILES=	asciidoc.conf docbook45.conf \
		filters/code/code-filter.conf \
		filters/graphviz/graphviz-filter.conf \
		filters/latex/latex-filter.conf \
		filters/music/music-filter.conf \
		filters/source/source-highlight-filter.conf \
		help.conf html4.conf html5.conf \
		lang-de.conf lang-el.conf lang-en.conf lang-es.conf \
		lang-fr.conf lang-hu.conf lang-it.conf lang-nl.conf \
		lang-pt-BR.conf lang-ru.conf lang-uk.conf \
		latex.conf slidy.conf text.conf wordpress.conf \
		xhtml11.conf xhtml11-quirks.conf

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MVIM}
MAKE_ENV+=	vimdir=${PREFIX}/share/vim/${VIM_DATADIR}
PLIST_SUB+=	VIM_DATADIR=${VIM_DATADIR}
VIM__DATADIR!=	${MAKE} -C ../../editors/vim/ -V _DATADIR
.else
PLIST_SUB+=	VIM_DATADIR=""
.endif

post-patch:
.for conf_file in ${CONF_FILES}
	@cd ${WRKSRC}/ && ${MV} ${conf_file} ${conf_file}.sample
.endfor
.if ${PORT_OPTIONS:MVIM}
	@${REINPLACE_CMD} -e '/^vimdir = /d' ${WRKSRC}/Makefile.in
.endif

pre-install:
.if ${PORT_OPTIONS:MVIM}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/vim/${VIM_DATADIR}/
.endif

post-install:
.for conf_file in ${CONF_FILES}
	@if [ ! -f ${ETCDIR}/${conf_file} ]; then \
		${CP} -p ${STAGEDIR}${ETCDIR}/${conf_file}.sample ${STAGEDIR}${ETCDIR}/${conf_file}; \
	fi
.endfor

.include <bsd.port.mk>
