# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kiconvtool
PORTVERSION=	0.99
CATEGORIES=	sysutils

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Tool to preload kernel iconv charset tables

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	AMDmi3

USES=		iconv	# used by libkiconv, actually

PLIST_FILES=	sbin/${PORTNAME} etc/rc.d/kiconv \
		man/man8/${PORTNAME}.8.gz

.include <bsd.port.mk>
