# New ports collection makefile for:	ipa
# Date created:				2 December 2000
# Whom:					Andrey Simonenko
#
# $FreeBSD$
#

PORTNAME=	ipa
PORTVERSION=	1.0.2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.simon.org.ua/ipa/ \
		http://www.comsys.ntu-kpi.kiev.ua/~simon/ipa/

MAINTAINER=	simon@simon.org.ua

ALL_TARGET=	FreeBSD

MAN5=		ipa.5 ipa.conf.5
MAN8=		ipa.8 ipastat.8

post-install:
	strip ${PREFIX}/bin/ipa
	strip ${PREFIX}/bin/ipastat

.include <bsd.port.mk>
