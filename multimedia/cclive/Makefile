# Ports collection makefile for:    cclive
# Date created:		1 February 2009
# Whom:			Toni Gundogdu <legatvs@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	cclive
PORTVERSION=	0.2.2
CATEGORIES=	multimedia net
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	legatvs@gmail.com
COMMENT=	Lightweight command line video extraction utility

LIB_DEPENDS=	curl.5:${PORTSDIR}/ftp/curl

.if !defined(WITHOUT_MAN)
MAKE_ENV=	WITH_MAN=yes
MAN1=		cclive.1
.endif

MAKE_ENV+=	V=1

PLIST_FILES=	bin/cclive

USE_BZIP2=	yes
USE_GMAKE=	yes

.include <bsd.port.mk>
