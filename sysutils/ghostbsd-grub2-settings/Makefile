# New ports collection makefile for: GhostBSD settings for grub2
# Date created:        29 jun 2015
# Whom:                angelescuo@yahoo.com
#
# $FreeBSD$
#

PORTNAME=	ghostbsd-grub2-settings
PORTVERSION=	2.0
CATEGORIES=	sysutils

MAINTAINER=	angelescuo@yahoo.com
COMMENT=	GhostBSD grub2 settings

LICENSE=	BSD

USE_GITHUB=	yes
GH_ACCOUNT=	GhostBSD

NO_BUILD=	yes

RUN_DEPENDS=	grub-mkconfig:sysutils/grub2-pcbsd

do-install:
	${MKDIR} ${STAGEDIR}/boot/grub/themes/ghostbsd
	${MKDIR} ${STAGEDIR}/usr/local/etc/default
	${CP} -R  ${WRKSRC}/* ${STAGEDIR}/
.include <bsd.port.mk>
