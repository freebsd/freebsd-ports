# New ports collection makefile for:	expat
# Date created:		Thu Aug 26 14:38:07 CEST 1999
# Whom:			Dirk Froemberg <dirk@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	expat
PORTVERSION=	2.0.1
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	SF

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	XML 1.0 parser written in C

WITH_FBSD10_FIX=	yes
GNU_CONFIGURE=	yes
ALL_TARGET=	default
USE_LDCONFIG=	yes
MAN1=		xmlwf.1

SHLIB_MAJOR=	6

MAKE_ENV=	LIBCURRENT="${SHLIB_MAJOR}"
PLIST_SUB=	SHLIB_MAJOR="${SHLIB_MAJOR}"

list-depend-ports:
	cd ${PORTSDIR}; \
	${FIND} . -mindepth 3 -maxdepth 3 -name Makefile -execdir ${SH} -c \
		'${FIND} . -type f | ${GREP} -v CVS | ${XARGS} ${GREP} -q expat.5' \; \
		-print

.include <bsd.port.mk>
