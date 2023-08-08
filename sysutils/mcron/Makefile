PORTNAME=	mcron
PORTVERSION=	1.2.1
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	GNU

MAINTAINER=	ports@FreeBSD.org
COMMENT=	100% compatible replacement for Vixie cron
WWW=		https://www.gnu.org/software/mcron/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		guile:2.2,3.0 gmake pkgconfig
GNU_CONFIGURE=	yes

CONFLICTS_INSTALL=	interchange isc-cron # bin/crontab

TEST_TARGET=	check

INFO=		mcron

.include <bsd.port.mk>
