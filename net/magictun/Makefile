# New ports collection makefile for:	magictun
# Date created:		20 January 2003
# Whom:			roam@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	magictun
PORTVERSION=	0.1
CATEGORIES=	net
MASTER_SITES=	http://anight.org/magictun/dist/

MAINTAINER=	roam@FreeBSD.org
COMMENT=	"An LD_PRELOAD module for transparent HTTPS proxy redirection"

PLIST_FILES=	lib/magictun.so

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/magictun.so ${PREFIX}/lib/magictun.so

.include <bsd.port.mk>
