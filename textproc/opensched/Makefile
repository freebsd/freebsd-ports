# Created by: Daniel McRobb <dwm@caimis.com>
# $FreeBSD$

PORTNAME=	opensched
PORTVERSION=	0.1.0
PORTREVISION=	8
CATEGORIES=	textproc
MASTER_SITES=	http://hitachi-id.com/dlsoftware/opensched/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Project scheduler

LICENSE=	GPLv2

BROKEN=		unfetchable

USES=		gmake

ALL_TARGET=	build

PLIST_FILES=	bin/opensched man/man1/opensched.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/opensched ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/opensched.1 \
		${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
