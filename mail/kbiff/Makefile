# New ports collection makefile for:	kbiff
# Date created:		So  14 Jun 1998 13:09:18 CEST
# Whom:			andreas
#
# $FreeBSD$
#

PORTNAME=	kbiff
PORTVERSION=	3.6.3
PORTREVISION=	2
CATEGORIES=	mail kde
MASTER_SITES=	http://devel-home.kde.org/~granroth/kbiff/

MAINTAINER=	arved@FreeBSD.org
COMMENT=	"Mail notification utility for KDE with nice features"

LIB_DEPENDS=	intl.5:${PORTSDIR}/devel/gettext-old

USE_KDELIBS_VER=3
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=
CONFIGURE_ARGS+=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL} \
		--disable-fast-perl

MAN1=		kbiff.1

.include <bsd.port.mk>
