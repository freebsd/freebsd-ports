# Ports collection makefile for:  source-highlight
# Date created:			  24 Aug 2001
# Whom:				  Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	source-highlight
PORTVERSION=	1.5
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR= source-highlight

MAINTAINER=	kevlo@FreeBSD.org

GNU_CONFIGURE=	yes
.if defined(NOPORTDOCS)
MAKE_ENV+=	NOPORTDOCS="${NOPORTDOCS}"
.endif

MAN1=		source-highlight.1

.include <bsd.port.mk>
