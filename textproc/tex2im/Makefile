# ex:ts=8
# New ports collection makefile for:	tex2im
# Date created:			Nov 28, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	tex2im
PORTVERSION=	1.5
CATEGORIES=	textproc
MASTER_SITES=	http://www.nought.de/

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash2 \
		latex:${PORTSDIR}/print/teTeX \
		convert:${PORTSDIR}/graphics/ImageMagick

USE_REINPLACE=	yes

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
