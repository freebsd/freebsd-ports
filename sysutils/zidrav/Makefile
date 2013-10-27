# Created by: Cosmin Stroe <cstroe1@uic.edu>
# $FreeBSD$

PORTNAME=	zidrav
PORTVERSION=	1.2.0
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}4unix/${PORTVERSION}
DISTNAME=	zidrav4unix-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	A file corruption detection and repair program

LICENSE=	GPLv2

USES=		manpages:install
ALL_TARGET=	zidrav
PLIST_FILES=	bin/zidrav
MAN1=		zidrav.1

do-install:	install-all-manpages
	${INSTALL_PROGRAM} ${WRKSRC}/zidrav ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
