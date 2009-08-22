# ex:ts=8
# Ports collection makefile for:	clpbar
# Date created:			Sep 3, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	clpbar
PORTVERSION=	1.10.9
CATEGORIES=	misc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/bar-${PORTVERSION}
DISTNAME=	bar_${PORTVERSION}

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Command Line Progress Bar

WRKSRC=		${WRKDIR}/bar-${PORTVERSION}
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE= yes
MAKE_ARGS+=	CFLAGS+="${CFLAGS}"

MAN1=		bar.1
PLIST_FILES=	bin/bar

.include <bsd.port.mk>
