# New ports collection makefile for:	expat
# Date created:		Thu Aug 26 14:38:07 CEST 1999
# Whom:			Dirk Froemberg <dirk@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	expat
PORTVERSION=	1.95.5
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	expat

MAINTAINER=	kuriyama@FreeBSD.org

USE_LIBTOOL=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
ALL_TARGET=	default
INSTALLS_SHLIB=	yes
MAN1=		xmlwf.1

SHLIB_MAJOR=	4

MAKE_ENV=	LIBCURRENT="${SHLIB_MAJOR}" \
		SHELL="/bin/sh"
PLIST_SUB=	SHLIB_MAJOR="${SHLIB_MAJOR}"

.include <bsd.port.mk>
