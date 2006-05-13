# ex:ts=8
# New ports collection makefile for:	tex2im
# Date created:			Nov 28, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	tex2im
PORTVERSION=	1.8
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.nought.de/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts LaTeX formulas into high resolution pixmap graphics

RUN_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick \
		latex:${PORTSDIR}/print/teTeX \
		bash:${PORTSDIR}/shells/bash2

NO_BUILD=	yes

post-patch:
	@${REINPLACE_CMD} -e "s,^#!/bin/bash,#!${LOCALBASE}/bin/bash,g" ${WRKSRC}/tex2im

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tex2im ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
