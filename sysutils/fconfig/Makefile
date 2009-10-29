# New ports collection makefile for:	fconfig
# Date created:			Oct 26, 2009
# Whom:				thompsa@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	fconfig
PORTVERSION=	20080329
CATEGORIES=	sysutils
MASTER_SITES=	http://downloads.openwrt.org/sources/ \
		http://andrzejekiert.ovh.org/software/fconfig/

MAINTAINER=	thompsa@FreeBSD.org
COMMENT=	Read and modify RedBoot embedded boot configuration

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_GMAKE=	yes
PLIST_FILES=	sbin/fconfig

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fconfig ${PREFIX}/sbin

.include <bsd.port.mk>
