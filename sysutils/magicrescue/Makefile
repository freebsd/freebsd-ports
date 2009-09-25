# New ports collection makefile for:	magicrescue
# Date created:				18 Jul 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	magicrescue
PORTVERSION=	1.1.7
CATEGORIES=	sysutils
MASTER_SITES=	http://www.student.dtu.dk/~s042078/magicrescue/release/ \
		CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	A file recovery tool which recovers deleted files from a block device

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}
USE_PERL5_RUN=	yes
MAKE_JOBS_SAFE=	yes

MAN1=		dupemap.1 magicrescue.1 magicsort.1

post-patch:
	@${REINPLACE_CMD} -e 's|^#!/usr/bin/env.*|#!${PERL}|' \
		${WRKSRC}/magicsort

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
.for f in NEWS README
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
