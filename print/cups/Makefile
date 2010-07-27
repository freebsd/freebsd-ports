# ex:ts=8	-*-mode: makefile-*-
#
# New ports collection makefile for:	cups
# Date created:		2003-01-22
# Whom:			Alan Eldridge <alane@geeksrus.net>
#
# $FreeBSD$
#

PORTNAME=	cups
PORTVERSION=	1.4.4
CATEGORIES=	print
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Common UNIX Printing System: Metaport to install complete system

BUILD_DEPENDS=	espgs:${PORTSDIR}/${PKGCATEGORY}/cups-pstoraster \
		cupsd:${PORTSDIR}/${PKGCATEGORY}/cups-base
RUN_DEPENDS=	${BUILD_DEPENDS}

NO_BUILD=	yes
NO_INSTALL=	yes

.include <bsd.port.mk>
