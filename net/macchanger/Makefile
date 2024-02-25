PORTNAME=	macchanger
PORTVERSION=	1.7.0
PORTREVISION=	3
CATEGORIES=	net

MAINTAINER=	clutton@zoho.com
COMMENT=	GNU MAC Changer
WWW=		https://www.gnu.org/software/macchanger

LICENSE=	GPLv3

USE_GITHUB=	yes
GH_ACCOUNT=	alobbs

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
USES=		autoreconf makeinfo

INFO=		macchanger

PLIST_FILES=	bin/${PORTNAME} share/man/man1/${PORTNAME}.1.gz \
		%%DATADIR%%/OUI.list %%DATADIR%%/wireless.list

.include <bsd.port.mk>
