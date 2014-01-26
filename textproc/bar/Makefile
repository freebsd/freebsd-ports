# Created by: Erik Greenwald <erik@smluc.org>
# $FreeBSD$

PORTNAME=	bar
PORTVERSION=	1.4
DISTVERSIONSUFFIX=	-src
CATEGORIES=	textproc
MASTER_SITES=	http://www.theiling.de/downloads/

MAINTAINER=	erik@bz.bzflag.bz
COMMENT=	Cat with ASCII progress bar

USE_BZIP2=	yes
NO_BUILD=	yes
PLIST_FILES=	bin/bar
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bar ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
