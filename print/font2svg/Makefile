# ex:ts=8
# Ports collection makefile for:	font2svg
# Date created:			Jan 10, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	font2svg
PORTVERSION=	0.1.5
CATEGORIES=	print
MASTER_SITES=	http://www.gdv.uni-hannover.de/~peinecke/font2svg/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	All font to svg-font converter

USE_GHOSTSCRIPT_RUN=	yes

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

USE_REINPLACE=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/font2svg %%DATADIR%%/encodings %%DATADIR%%/font2svg.ps
PLIST_DIRS=	%%DATADIR%%

pre-everything::
.if !defined(WITH_GHOSTSCRIPT_AFPL) || ${WITH_GHOSTSCRIPT_AFPL} != yes
	@${ECHO_MSG} ""
	@${ECHO_MSG} "      Define WITH_GHOSTSCRIPT_AFPL=yes to use"
	@${ECHO_MSG} "      AFPL Postscript interpreter instead of GNU one"
	@${ECHO_MSG} ""
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|^#!/bin/bash|#!${LOCALBASE}/bin/bash| ; \
		 s|^font2svg_home=.*$$|font2svg_home=${DATADIR}| ; \
		 s|^non_gnu_getopt=.*$$|non_gnu_getopt=1|" ${WRKSRC}/font2svg

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/font2svg ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/encodings ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/font2svg.ps ${DATADIR}

.include <bsd.port.mk>
