# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	magicrescue
PORTVERSION=	1.1.9
CATEGORIES=	sysutils
MASTER_SITES=	http://www.itu.dk/people/jobr/magicrescue/release/ \
		CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	File recovery tool which recovers deleted files from a block device

LICENSE=	GPLv2

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}
USE_PERL5_RUN=	yes

MAN1=		dupemap.1 magicrescue.1 magicsort.1

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|^#!/usr/bin/env.*|#!${PERL}|' \
		${WRKSRC}/magicsort

.if ${PORT_OPTIONS:MDOCS}
post-install:
	${MKDIR} ${DOCSDIR}
.for f in NEWS README
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
