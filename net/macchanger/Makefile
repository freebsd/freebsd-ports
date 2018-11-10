# $FreeBSD$

PORTNAME=	macchanger
PORTVERSION=	1.7.0
PORTREVISION=	2
CATEGORIES=	net

MAINTAINER=	clutton@zoho.com
COMMENT=	GNU MAC Changer

LICENSE=	GPLv3

USE_GITHUB=	true
GH_ACCOUNT=	alobbs

GNU_CONFIGURE=	yes
USES=		autoreconf makeinfo

INFO=		macchanger

PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz \
		%%DATADIR%%/OUI.list %%DATADIR%%/wireless.list

.include <bsd.port.mk>
