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

USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include "${.CURDIR}/../linux-seamonkey/Makefile.common"
.include <bsd.port.mk>
