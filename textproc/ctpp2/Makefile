# New ports collection makefile for:   ctpp2
# Date created:         25 Jan 2008
# Whom:                 reki@reki.ru (Andrei V. Shetuhin)
#
# $FreeBSD$
#

PORTNAME=	ctpp2
PORTVERSION=	2.5.18
PORTREVISION=	1
CATEGORIES=	textproc devel
MASTER_SITES=	http://ctpp.havoc.ru/download/

MAINTAINER=	reki@reki.ru
COMMENT=	C++ library to use templates in C/C++ projects, version 2

USE_CMAKE=	yes
USE_LDCONFIG=	yes
USE_GETTEXT=	yes
USE_ICONV=	yes

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

MAN1=	ctpp2c.1 ctpp2vm.1 ctpp2i.1 ctpp2json.1 ctpp2-config.1

.include <bsd.port.mk>
