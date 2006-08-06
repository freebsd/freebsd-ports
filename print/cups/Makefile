# ex:ts=8	-*-mode: makefile-*-
#
# New ports collection makefile for:	cups
# Date created:		2003-01-22
# Whom:			Alan Eldridge <alane@geeksrus.net>
#
# $FreeBSD$
#

PORTNAME=	cups
PORTVERSION=	1.2.2
CATEGORIES=	print
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	asa@agava.com
COMMENT=	The Common UNIX Printing System: Metaport to install complete system

.if make(package)
DEPENDS_TARGET="package"
.endif # make(package)

LIB_DEPENDS+=	cups.2:${PORTSDIR}/print/cups-base
RUN_DEPENDS+=	espgs:${PORTSDIR}/print/cups-pstoraster

NO_BUILD=	true

do-build:

do-install:

.include <bsd.port.mk>
