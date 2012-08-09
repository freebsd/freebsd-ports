# New ports collection makefile for:	libfvde
# Date created:		07 August 2012
# Whom:			Kubilay Kocak <koobs.freebsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	libfvde
PORTVERSION=	20120519
CATEGORIES=	sysutils
MASTER_SITES=	GOOGLE_CODE
DISTFILES=	${PORTNAME}-experimental-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	koobs.freebsd@gmail.com
COMMENT=	Library and tools for reading FileVault (FVDE) encrypted volumes

LICENSE=	LGPL3

GNU_CONFIGURE=	yes
USE_GNOME=	libxml2 gnomehack
USE_LDCONFIG=	yes

MAN1=	bdeinfo.1 bdemount.1
MAN3=	libbde.3

.include <bsd.port.mk>
