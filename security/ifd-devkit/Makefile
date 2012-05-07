# New ports collection makefile for:	ifd-devkit
# Date created:		23 August 2002
# Whom:			Bruce M Simpson
#
# $FreeBSD$
#

PORTNAME=	ifd-devkit
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.linuxnet.com/drivers/readers/files/

MAINTAINER=	arved@FreeBSD.org
COMMENT=	IFD Handler Developer's Kit for MUSCLE PC/SC Lite

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	pcsclite.1:${PORTSDIR}/devel/pcsc-lite

USE_LDCONFIG=	yes

NOMAN=

DEPRECATED=	Conflicts with its dependency. Has not been updated for years
EXPIRATION_DATE=2012-05-21

.include <bsd.port.mk>
