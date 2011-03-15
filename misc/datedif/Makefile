# ex:ts=8
# New ports collection makefile for:	datedif
# Date created:			Jun 16, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	datedif
PORTVERSION=	0.9.1.4
CATEGORIES=	misc
MASTER_SITES=	http://keyserver.kjsl.com/~jharris/distfiles/
DISTNAME=	${PORTNAME}-0.9.1-4

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Calculates the number of days between two dates

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

ALL_TARGET=
PLIST_FILES=	bin/datedif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/datedif ${PREFIX}/bin

.include <bsd.port.mk>
