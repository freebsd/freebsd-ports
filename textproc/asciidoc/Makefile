# Created by: anholt@FreeBSD.org
# $FreeBSD$

PORTNAME=	asciidoc
PORTVERSION=	8.6.9
PORTREVISION=	6
CATEGORIES=	textproc
MASTER_SITES=	SF

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Text document format for writing short documents and man pages

LICENSE=	GPLv2 MIT
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING

RUN_DEPENDS=	docbook-xsl>=0:textproc/docbook-xsl

GNU_CONFIGURE=	yes
NO_ARCH=	yes
USE_GNOME=	libxml2:run libxslt:run
USES=		gmake gnome python:2.7 shebangfix

SHEBANG_FILES=	a2x.py \
		asciidoc.py \
		asciidocapi.py \
		filters/code/code-filter.py \
		filters/graphviz/graphviz2png.py \
		filters/latex/latex2png.py \
		filters/music/music2png.py

post-patch:
	@${REINPLACE_CMD} -e '/^INSTALL_PROG/ s|INSTALL_PROGRAM|INSTALL_SCRIPT|; s|\.conf|&.sample|' ${WRKSRC}/Makefile.in
	@${FIND} ${WRKSRC} -name '*.conf' | ${XARGS} -I % ${MV} % %.sample

post-install:
	${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/
	${INSTALL_DATA} ${WRKSRC}/asciidocapi.py ${STAGEDIR}${PYTHON_SITELIBDIR}/

.include <bsd.port.mk>
