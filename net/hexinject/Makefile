# New ports collection makefile for:	hexinject
# Date created:		2010-10-24
# Whom:			Sofian Brabez <sbrabez@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	hexinject
PORTVERSION=	1.1
CATEGORIES=	net security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	sbrabez@gmail.com
COMMENT=	HexInject is a very versatile packet injector and sniffer

PLIST_FILES=	bin/${PORTNAME}

WRKSRC=	${WRKDIR}/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
