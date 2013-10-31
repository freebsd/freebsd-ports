# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kiconvtool
PORTVERSION=	0.97
CATEGORIES=	sysutils
MASTER_SITES=	http://mirror.amdmi3.ru/distfiles/ \
		LOCAL/amdmi3

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Tool to preload kernel iconv charset tables

USES=		iconv	# used by libkiconv, actually

PLIST_FILES=	sbin/${PORTNAME} etc/rc.d/kiconv \
		man/man8/${PORTNAME}.8.gz

.include <bsd.port.mk>
