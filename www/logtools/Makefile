# New ports collection makefile for:	logtools
# Date created:		8 January 2002
# Whom:			Mark Huizer; Eindhoven
#
# $FreeBSD$
#

PORTNAME=	logtools
PORTVERSION=	0.13d
CATEGORIES=	www
MASTER_SITES=	http://www.coker.com.au/logtools/ \
  		LOCAL/chinsan/logtools/
EXTRACT_SUFX=	.tgz

MAINTAINER=	scjamorim@bsd.com.br
COMMENT=	Useful tools to deal with CLF files (Common Log File format)

PLIST_FILES=	bin/clfmerge \
		bin/clfsplit \
		bin/clfdomainsplit \
		bin/logprn \
		bin/funnel \
		etc/clfdomainsplit.cfg

GNU_CONFIGURE=	yes
MAN1=		clfmerge.1 logprn.1 funnel.1 clfsplit.1 clfdomainsplit.1

.include <bsd.port.mk>
