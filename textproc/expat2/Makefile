# New ports collection makefile for:	expat
# Date created:		Thu Aug 26 14:38:07 CEST 1999
# Whom:			Dirk Froemberg <dirk@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	expat
PORTVERSION=	1.95.8
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	expat

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	XML 1.0 parser written in C

USE_INC_LIBTOOL_VER=13
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
ALL_TARGET=	default
INSTALLS_SHLIB=	yes
MAN1=		xmlwf.1

SHLIB_MAJOR=	5

MAKE_ENV=	LIBCURRENT="${SHLIB_MAJOR}" \
		SHELL="/bin/sh"
PLIST_SUB=	SHLIB_MAJOR="${SHLIB_MAJOR}"

list-depend-ports:
	cd ${PORTSDIR}; \
	find . -mindepth 3 -maxdepth 3 -name Makefile -execdir sh -c \
		'find . -type f | grep -v CVS | xargs grep -q expat.5' \; \
		-print

.include <bsd.port.mk>
