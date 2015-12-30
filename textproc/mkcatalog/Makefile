# Created by: shige
# $FreeBSD$

PORTNAME=	mkcatalog
PORTVERSION=	1.1
CATEGORIES=	textproc
MASTER_SITES=	# none
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Maintenance utility for sgml catalog files

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
NO_ARCH=	yes

SUB_FILES=	mkcatalog
PLIST_FILES=	sbin/mkcatalog

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/mkcatalog \
		${STAGEDIR}${PREFIX}/sbin/mkcatalog

.include <bsd.port.mk>
