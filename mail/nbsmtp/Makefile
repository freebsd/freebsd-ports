# New ports collection makefile for:	nbsmtp
# Date created:		5 May 2001
# Whom:			Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	nbsmtp
PORTVERSION=	0.8
CATEGORIES=	mail
MASTER_SITES=	http://physeeks.dyndns.org:8000/download/ \
		ftp://ftp.nuug.no/pub/anders/distfiles/
EXTRACT_SUFX=	.tgz

MAINTAINER=	anders@FreeBSD.org

NO_WRKSUBDIR=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nbsmtp ${PREFIX}/bin/

.include <bsd.port.mk>
