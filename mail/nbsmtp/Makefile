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

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple program for outgoing SMTP delivery

NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/nbsmtp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nbsmtp ${PREFIX}/bin/

.include <bsd.port.mk>
