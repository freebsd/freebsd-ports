# New ports collection makefile for:	rblsmtpd
# Date created:		30 October 1998
# Whom:			John Saunders <john@nlc.net.au>
#
# $FreeBSD$
#

PORTNAME=	rblsmtpd
PORTVERSION= 	0.70
CATEGORIES=	mail
MASTER_SITES=	ftp://koobera.math.uic.edu/www/software/

MAINTAINER=	john@nlc.net.au

NO_PACKAGE=	Unsure of djb's license

ALL_TARGET=	it
INSTALL_TARGET=	setup check

SCRIPTS_ENV=	BINOWN="${BINOWN}" BINGRP="${BINGRP}" BINMODE="${BINMODE}" \
		MANMODE="${MANMODE}" CFLAGS="${CFLAGS}"

MAN8=		rblsmtpd.8 antirbl.8

.include <bsd.port.mk>
