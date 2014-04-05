# Created by: ijliao
# $FreeBSD$

PORTNAME=	mcron
PORTVERSION=	1.0.4
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	mcron

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A 100% compatible replacement for Vixie cron

BUILD_DEPENDS=	guile>=1.8.6:${PORTSDIR}/lang/guile
RUN_DEPENDS:=	${BUILD_DEPENDS}

GNU_CONFIGURE=	yes
MAKEFILE=	makefile

INFO=		mcron

NO_STAGE=	yes
.include <bsd.port.mk>
