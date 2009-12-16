# ex:ts=8
# New ports collection makefile for:	csup
# Date created:				27 January 2006
# Whom:					Maxime Henrion <mux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	csup
PORTVERSION=	20060318
CATEGORIES=	net devel
MASTER_SITES=	http://www.mu.org/~mux/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	mux
DISTNAME=	${PORTNAME}-snap-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	mux@FreeBSD.org
COMMENT=	A rewrite of the CVSup file updating client in C

DEPRECATED=		is already included in base system of all supported releases
EXPIRATION_DATE=	2010-02-16

WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_FILES=	bin/csup \
		man/man1/csup.1.gz

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 700014 || ( ${OSVERSION} >= 601101 && ${OSVERSION} < 700000 )
IGNORE=		is already in the base system
.endif

.include <bsd.port.post.mk>
