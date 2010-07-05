# New ports collection makefile for:	linux-nvu
# Date created:				2004-05-10
# Whom:					Ilya Khamushkin
#
# $FreeBSD$
#

PORTNAME=	nvu
PORTVERSION=	1.0
DISTVERSIONSUFFIX=	-pc-linux2.6.10-gnu
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://cvs.nvu.com/download/ CSME

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A complete Web Authoring System

DEPRECATED=	NVU 1.0, released June 2005, is the last official release of NVU. \
		Kompozer has picked up where NVU has left off. Please consider using \
		${PORTSDIR}/www/kompozer instead
EXPIRATION_DATE=	2010-08-05

USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include "${.CURDIR}/../linux-seamonkey/Makefile.common"
.include <bsd.port.mk>
