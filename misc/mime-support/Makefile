# New ports collection makefile for:	mime-support
# Date created:		7 March 2003
# Whom:			Simon 'corecode' Schubert <corecode@corecode.ath.cx>
#
# $FreeBSD$
#

PORTNAME=	mime-support
PORTVERSION=	3.32.1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_DEBIAN_POOL}
DISTNAME=	${PORTNAME}_${PORTVERSION:C/(.*)\.([^.])/\1-\2/}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	MIME Media Types list

WRKSRC=		${WRKDIR}/${PORTNAME}

NO_BUILD=	yes
PLIST_FILES=	etc/mime.types

do-install:
	${INSTALL_DATA} ${WRKSRC}/mime.types ${PREFIX}/etc

.include <bsd.port.mk>
