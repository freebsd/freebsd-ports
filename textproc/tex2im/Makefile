# ex:ts=8
# New ports collection makefile for:	tex2im
# Date created:			Nov 28, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	tex2im
PORTVERSION=	1.8
PORTREVISION=	9
CATEGORIES=	textproc
MASTER_SITES=	http://www.nought.de/

MAINTAINER=	turutani@scphys.kyoto-u.ac.jp
COMMENT=	Converts LaTeX formulas into high resolution pixmap graphics

RUN_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick \
		bash:${PORTSDIR}/shells/bash

USE_TEX=	tetex
NO_BUILD=	yes
PLIST_FILES=	bin/tex2im
PORTEXAMPLES=	example1.png example1.tex example2.png example2.tex \
		example3.png example3.tex example4.png example4.tex \
		fig_1.eps

post-patch:
	@${REINPLACE_CMD} -e "s,^#!/bin/bash,#!${LOCALBASE}/bin/bash,g" ${WRKSRC}/tex2im

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tex2im ${PREFIX}/bin
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${INSTALL_DATA} ${PORTEXAMPLES} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
