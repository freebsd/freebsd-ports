# New ports collection makefile for:    dhcdrop
# Date created:         Aug 9 2009
# Whom:                 Nick F
#
# $FreeBSD$
#

PORTNAME=	dhcdrop
PORTVERSION=	0.5
CATEGORIES=	net-mgmt sysutils
MASTER_SITES=	http://www.netpatch.ru/projects/dhcdrop/

MAINTAINER=	ffault@gmail.com
COMMENT=	Tool for searching and suppressing false DHCP servers

USE_BZIP2=	yes
GNU_CONFIGURE=	yes

MAN8=		${PORTNAME}.8
MANLANG=	"" ru

PLIST_FILES=	sbin/dhcdrop

OPTIONS=	STATIC "Build a static version of dhcdrop" off

.include <bsd.port.options.mk>

.if defined(WITH_STATIC)
CONFIGURE_ARGS+=--enable-static-build
.endif

.include <bsd.port.mk>
