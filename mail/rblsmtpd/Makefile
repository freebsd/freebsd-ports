# New ports collection makefile for:	rblsmtpd
# Version required:     0.70
# Date created:		30 October 1998
# Whom:			John Saunders <john@nlc.net.au>
#
# $Id$
#

DISTNAME=	rblsmtpd-0.70
CATEGORIES=	mail
MASTER_SITES=	ftp://koobera.math.uic.edu/pub/software/

MAINTAINER=	john@nlc.net.au

NO_PACKAGE=	Unsure of djb's license

ALL_TARGET=	it
INSTALL_TARGET=	setup check

SCRIPTS_ENV=	BINOWN="${BINOWN}" BINGRP="${BINGRP}" BINMODE="${BINMODE}" \
		MANMODE="${MANMODE}" CFLAGS="${CFLAGS}"

MAN8=		rblsmtpd.8 antirbl.8

.include <bsd.port.mk>
