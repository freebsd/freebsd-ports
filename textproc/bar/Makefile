# New ports collection makefile for:	bar
# Date created:			Wed May 18 2005
# Whom:				Erik Greenwald <erik@smluc.org>
#
# $FreeBSD$
#

PORTNAME=	bar
PORTVERSION=	1.3.1
CATEGORIES=	textproc
MASTER_SITES=	http://www.theiling.de/downloads/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	erik@smluc.org
COMMENT=	Cat with ASCII progress bar

USE_BZIP2=	yes
NO_BUILD=	yes
PLIST_FILES=	bin/bar
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bar ${PREFIX}/bin

.include <bsd.port.mk>
