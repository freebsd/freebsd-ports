# New ports collection makefile for:	nbsmtp
# Date created:		5 May 2001
# Whom:			Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	nbsmtp
PORTVERSION=	0.98
CATEGORIES=	mail
MASTER_SITES=	http://www.gentoo-es.org/~ferdy/ \
		http://www.it.uc3m.es/~ferdy/nbsmtp/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple program for outgoing SMTP delivery

PLIST_FILES=	bin/nbsmtp
GNU_CONFIGURE=	yes

MAN5=	nbsmtprc.5
MAN8=	nbsmtp.8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nbsmtp ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/nbsmtp.8 ${MAN8PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/nbsmtprc.5 ${MAN5PREFIX}/man/man5

.include <bsd.port.mk>
