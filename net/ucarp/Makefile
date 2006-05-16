# New ports collection makefile for:   ucarp
# Date created:                2005-05-06
# Whom:                        Meno Abels <meno.abels@adviser.com>
#
# $FreeBSD$
#

PORTNAME=	ucarp
PORTVERSION=	1.2
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.ucarp.org/pub/ucarp/

MAINTAINER=	meno.abels@adviser.com
COMMENT=	Userlevel Common Address Redundancy Protocol

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--disable-nls
USE_BZIP2=	yes
GNU_CONFIGURE=	yes

PLIST_FILES=	sbin/ucarp

.include <bsd.port.mk>
