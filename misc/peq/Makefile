# New ports collection makefile for:	peq
# Version required:			0.7.1
# Date created:				2 April 1999
# Whom:					Gordon Greeff
#
# $FreeBSD$
#

DISTNAME=	peq-0.7.1
CATEGORIES=	games
MASTER_SITES=	http://silverstone.fortunecity.com/jaguar/37/ \
		ftp://lost.iafrica.com/pub/peq/

MAINTAINER=	gvg@uunet.co.za

USE_QT=         yes

post-install:
	strip ${PREFIX}/bin/peq
	strip ${PREFIX}/bin/xpeq

.include <bsd.port.mk>
