# Created by: ijliao
# $FreeBSD$

PORTNAME=	tex2im
PORTVERSION=	1.8
PORTREVISION=	9
CATEGORIES=	textproc
MASTER_SITES=	http://www.nought.de/

MAINTAINER=	TsurutaniNaoki@gmail.com
COMMENT=	Converts LaTeX formulas into high resolution pixmap graphics

RUN_DEPENDS=	convert:graphics/ImageMagick \
		bash:shells/bash

USE_TEX=	latex
NO_BUILD=	yes
PLIST_FILES=	bin/tex2im
PORTEXAMPLES=	example1.png example1.tex example2.png example2.tex \
		example3.png example3.tex example4.png example4.tex \
		fig_1.eps

post-patch:
	@${REINPLACE_CMD} -e "s,^#!/bin/bash,#!${LOCALBASE}/bin/bash,g" ${WRKSRC}/tex2im

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tex2im ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${INSTALL_DATA} ${PORTEXAMPLES} \
		${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
