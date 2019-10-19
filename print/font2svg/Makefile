# Created by: ijliao
# $FreeBSD$

PORTNAME=	font2svg
PORTVERSION=	1.0
PORTREVISION=	6
CATEGORIES=	print
MASTER_SITES=	https://BSDforge.com/projects/source/print/font2svg/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	All fonts to svg-font converter

LICENSE=	GPLv2

RUN_DEPENDS=	bash:shells/bash

USES=		ghostscript:run
NO_BUILD=	yes

PLIST_FILES=	bin/font2svg %%DATADIR%%/encodings %%DATADIR%%/font2svg.ps

post-patch:
	@${REINPLACE_CMD} -e "s|^#!/bin/bash|#!/usr/bin/env bash| ; \
		 s|^font2svg_home=.*$$|font2svg_home=${DATADIR}|" \
		 ${WRKSRC}/font2svg.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/font2svg.sh ${STAGEDIR}${PREFIX}/bin/font2svg
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/encodings ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/font2svg.ps ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
