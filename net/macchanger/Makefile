# $FreeBSD$

PORTNAME=	macchanger
PORTVERSION=	1.7.0
CATEGORIES=	net

MAINTAINER=	clutton@zoho.com
COMMENT=	GNU MAC Changer

LICENSE=	GPLv3

USE_GITHUB=	true
GH_ACCOUNT=	alobbs
GH_COMMIT=	f4f66e1

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	aclocal autoconf automake autoheader
AUTOMAKE_ARGS=	--add-missing

INFO=		macchanger

PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz \
		%%DATADIR%%/OUI.list %%DATADIR%%/wireless.list
PLIST_DIRS=	%%DATADIR%%

.include <bsd.port.mk>
