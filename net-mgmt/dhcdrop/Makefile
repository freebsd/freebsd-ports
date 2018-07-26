# Created by: Nick F <ffault@gmail.com>
# $FreeBSD$

PORTNAME=	dhcdrop
PORTVERSION=	0.5
PORTREVISION=	2
CATEGORIES=	net-mgmt sysutils
MASTER_SITES=	http://www.netpatch.ru/projects/dhcdrop/

MAINTAINER=	ffault@gmail.com
COMMENT=	Tool for searching and suppressing false DHCP servers

LICENSE=	GPLv2

USES=		autoreconf libtool tar:bzip2
USE_CSTD=	gnu89
GNU_CONFIGURE=	yes

PLIST_FILES=	sbin/dhcdrop man/man8/dhcdrop.8.gz \
		man/ru/man8/dhcdrop.8.gz

OPTIONS_DEFINE=	STATIC
STATIC_DESC=	Build a static version of dhcdrop

STATIC_CONFIGURE_ENABLE=	static-build

.include <bsd.port.mk>
