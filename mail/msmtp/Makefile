# Ports collection makefile for:  msmtp
# Date created:                   22 Aug 2003
# Whom:                           R.I.Pienaar <rip@devco.net>
#
# $FreeBSD$
#

PORTNAME=	msmtp
PORTVERSION=	0.4.2
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	msmtp

MAINTAINER=	rip@devco.net
COMMENT=	SMTP \"plugin\" for MUAs

USE_GETOPT_LONG= yes

MAN1=		msmtp.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/msmtp ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/msmtp.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
