# New ports collection makefile for:   cups
# Date created:        05 January 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	cups
PORTVERSION=	${VERSION}
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	# empty
DISTFILES=	# none
EXTRACT_ONLY=	# empty

MAINTAINER=	jah4007@cs.rit.edu

VERSION=	1.1.12

LIB_DEPENDS=	cups.2:${PORTSDIR}/print/cups-base
RUN_DEPENDS=	${LOCALBASE}/sbin/cupsaddsmb:${PORTSDIR}/print/cups-lpr

NO_BUILD=	true
do-install:	# empty

.include <bsd.port.mk>
