# New ports collection makefile for:	sqtop
# Date created:		2010-09-05
# Whom:			Marco Steinbach <coco@webdev.c0c0.intra>
#
# $FreeBSD$
#

PORTNAME=	sqtop
DISTVERSION=	2010-06-03
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	coco@executive-computing.de
COMMENT=	Console-based display of Squid proxy connections

USE_BZIP2=	yes

PLIST_FILES=	bin/sqtop

MAN1=		sqtop.1

GNU_CONFIGURE=	yes

OPTIONS=	NCURSES	"Enable ncurses user interface"	On

.include <bsd.port.options.mk>

.if defined(WITHOUT_NCURSES)
CONFIGURE_ARGS+=	--disable-ui
.endif

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
