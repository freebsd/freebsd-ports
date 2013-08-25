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
VIM_DESC=	Install Vim ftdetect & syntax files

GNU_CONFIGURE=	yes
USE_PYTHON=	-2.7
USES=		gmake

MAN1=		a2x.1 asciidoc.1

CONFFILES=	asciidoc.conf docbook45.conf \
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
PLIST_SUB+=	VIM="" VIM_DATADIR=${VIM_DATADIR}
VIM__DATADIR!=	${MAKE} -C ../../editors/vim/ -V _DATADIR
.else
PLIST_SUB+=	VIM="@comment " VIM_DATADIR=""
.endif

post-patch:
.for f in ${CONFFILES}
	@cd ${WRKSRC} && ${MV} ${f} ${f}.sample
.endfor
.if ${PORT_OPTIONS:MVIM}
	@${REINPLACE_CMD} -e '/^vimdir = /d' ${WRKSRC}/Makefile.in
.endif

pre-install:
.if ${PORT_OPTIONS:MVIM}
	@${MKDIR} ${PREFIX}/share/vim/${VIM_DATADIR}/
.endif

post-install:
.for f in ${CONFFILES}
	@if [ ! -f ${ETCDIR}/${f} ]; then \
		${CP} -p ${ETCDIR}/${f}.sample ${ETCDIR}/${f} ; \
	fi
.endfor

.include <bsd.port.mk>
