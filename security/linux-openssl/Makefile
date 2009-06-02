# New ports collection makefile for:	linux-openssl
# Date created:		2006-08-04
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	openssl
PORTVERSION=	0.9.7f
PORTREVISION=	2
CATEGORIES=	security linux
DISTNAME=	${PORTNAME}-${PORTVERSION}-7.10

MAINTAINER=	acm@FreeBSD.org
COMMENT=	SSL and crypto library (Linux Version)

CONFLICTS=	linux-f8-openssl-[0-9]* linux-f10-openssl-[0-9]*

USE_LINUX_RPM=	yes
LINUX_DIST_VER=	4
USE_LDCONFIG=	yes
DESCR=	${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
