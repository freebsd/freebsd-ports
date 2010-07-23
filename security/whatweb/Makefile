# New ports collection makefile for:    whatweb
# Date created:				2010-04-11
# Whom:					Niels Heinen
#
# $FreeBSD$
#

PORTNAME=	whatweb
PORTVERSION=	0.4.4
CATEGORIES=	security www
MASTER_SITES=	http://www.morningstarsecurity.com/downloads/

MAINTAINER=	niels@FreeBSD.org
COMMENT=	A tool to fingerprint web site components

USE_RUBY=	yes
NO_BUILD=	yes
PORTDOCS=	README INSTALL CHANGELOG TODO How-to-develop-WhatWeb-plugins-1.1.txt
MAN1=		${PORTNAME}.1
MANCOMPRESSED=	no

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e \
	's!/usr/share/whatweb/!${RUBY_SITELIBDIR}/${PORTNAME}!' \
	${WRKSRC}/${PORTNAME}

do-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.	for i in ${PORTDOCS}
		${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.	endfor
.endif
.for DIR in plugins lib plugin-development
	( cd ${WRKSRC}/${DIR} && \
	${COPYTREE_SHARE} . ${RUBY_SITELIBDIR}/${PORTNAME}/${DIR} )
.endfor
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MANPREFIX}/man/man1
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.post.mk>
