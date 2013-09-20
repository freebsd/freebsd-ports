# Created by: Daniel McRobb <dwm@caimis.com>
# $FreeBSD$

PORTNAME=	opensched
PORTVERSION=	0.1.0
PORTREVISION=	8
CATEGORIES=	textproc
MASTER_SITES=	http://hitachi-id.com/dlsoftware/opensched/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A project scheduler

LICENSE=	GPLv2

USE_GMAKE=	yes
ALL_TARGET=	build

MAN1=		opensched.1
PLIST_FILES=	bin/opensched

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/opensched ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/opensched.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
