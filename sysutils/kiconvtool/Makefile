# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kiconvtool
PORTVERSION=	0.96
CATEGORIES=	sysutils
MASTER_SITES=	http://mirror.amdmi3.ru/distfiles/ \
		LOCAL/amdmi3

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Tool to preload kernel iconv charset tables

USES=		iconv	# used by libkiconv, actually

PLIST_FILES=	sbin/kiconvtool etc/rc.d/kiconv

MAN8=		kiconvtool.8

NO_STAGE=	yes
.include <bsd.port.mk>
