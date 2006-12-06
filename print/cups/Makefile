# ex:ts=8	-*-mode: makefile-*-
#
# New ports collection makefile for:	cups
# Date created:		2003-01-22
# Whom:			Alan Eldridge <alane@geeksrus.net>
#
# $FreeBSD$
#

PORTNAME=	cups
PORTVERSION=	1.2.7
CATEGORIES=	print
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Common UNIX Printing System: Metaport to install complete system

RUN_DEPENDS=	espgs:${PORTSDIR}/print/cups-pstoraster \
		cupsd:${PORTSDIR}/print/cups-base
.if make(package)
DEPENDS_TARGET="package"
.endif # make(package)

NO_BUILD=	yes
do-install:	# empty

.include <bsd.port.mk>
