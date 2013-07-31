# Created by: Nick F <ffault@gmail.com>
# $FreeBSD$

PORTNAME=	dhcdrop
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	net-mgmt sysutils
MASTER_SITES=	http://www.netpatch.ru/projects/dhcdrop/

MAINTAINER=	ffault@gmail.com
COMMENT=	Tool for searching and suppressing false DHCP servers

USE_BZIP2=	yes
USE_CSTD=	gnu89
GNU_CONFIGURE=	yes

MAN8=		${PORTNAME}.8
MANLANG=	"" ru

PLIST_FILES=	sbin/dhcdrop
PLIST_DIRSTRY=	man/ru/man8 man/ru

OPTIONS_DEFINE=	STATIC
STATIC_DESC=	Build a static version of dhcdrop

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSTATIC}
CONFIGURE_ARGS+=--enable-static-build
.endif

.include <bsd.port.mk>
