# New ports collection makefile for:   ctpp2
# Date created:         25 Jan 2008
# Whom:                 reki@reki.ru (Andrei V. Shetuhin)
#
# $FreeBSD$
#

PORTNAME=	ctpp2
PORTVERSION=	2.1.1
CATEGORIES=	textproc devel
MASTER_SITES=	http://ctpp.havoc.ru/download/

MAINTAINER=	reki@reki.ru
COMMENT=	C++ library to use templates in C/C++ projects, version 2

BUILD_DEPENDS=	cmake:${PORTSDIR}/devel/cmake

USE_LDCONFIG=	yes

do-configure:
	@cd ${WRKSRC} && ${LOCALBASE}/bin/cmake ${WRKSRC}

.include <bsd.port.mk>
