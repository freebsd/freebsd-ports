# New ports collection makefile for:	peq
# Date created:				2 April 1999
# Whom:					Gordon Greeff
#
# $FreeBSD$
#

PORTNAME=	peq
PORTVERSION=	0.7.1
CATEGORIES=	misc games
MASTER_SITES=	http://silverstone.fortunecity.com/jaguar/37/ \
		ftp://lost.iafrica.com/pub/peq/

MAINTAINER=	gvg@uunet.co.za

USE_QT_VER=	1

post-install:
	strip ${PREFIX}/bin/peq
	strip ${PREFIX}/bin/xpeq

.include <bsd.port.mk>
