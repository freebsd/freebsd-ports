PORTNAME=	mcron
PORTVERSION=	1.2.3
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	GNU

MAINTAINER=	ports@FreeBSD.org
COMMENT=	100% compatible replacement for Vixie cron
WWW=		https://www.gnu.org/software/mcron/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake guile:3.0 pkgconfig
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

TEST_TARGET=	check

CONFLICTS_INSTALL=	interchange isc-cron # bin/crontab

INFO=		mcron

.include <bsd.port.mk>
