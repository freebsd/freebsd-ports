# New ports collection makefile for:	kiconvtool
# Date created:		25 Jun 2008
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kiconvtool
PORTVERSION=	0.95
CATEGORIES=	sysutils
MASTER_SITES=	http://mirror.amdmi3.ru/distfiles/ \
		LOCAL/amdmi3

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Tool to preload kernel iconv charset tables

USE_ICONV=	yes	# used by libkiconv, actually

PLIST_FILES=	sbin/kiconvtool etc/rc.d/kiconv

MAN8=		kiconvtool.8

.include <bsd.port.mk>
