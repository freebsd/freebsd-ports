# New ports collection makefile for:	scponly
# Date created:				2002/07/23
# Whom:					mcglk@artlogix.com
#
# $FreeBSD$
#

PORTNAME=	scponly
PORTVERSION=	2.4
CATEGORIES=	shells
MASTER_SITES=	http://www.sublimation.org/scponly/
EXTRACT_SUFX=	.tgz

MAINTAINER=	mcglk@artlogix.com

MAN8=	scponly.8

post-install:
	strip ${PREFIX}/sbin/scponly

.include <bsd.port.mk>
