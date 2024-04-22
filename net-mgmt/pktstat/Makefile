PORTNAME=	pktstat
PORTVERSION=	1.8.5
PORTREVISION=	2
CATEGORIES=	net-mgmt

MAINTAINER=	freebsd@sosend.de
COMMENT=	Network traffic viewer
WWW=		https://github.com/dleonard0/pktstat

LICENSE=	PD

USE_GITHUB=	yes
GH_ACCOUNT=	dleonard0
GH_TAGNAME=	46935839b

USES=		autoreconf ncurses
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

PLIST_FILES=	bin/${PORTNAME} share/man/man1/${PORTNAME}.1.gz

.include <bsd.port.mk>
