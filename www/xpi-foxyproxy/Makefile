# New ports collection makefile for:	xpi-foxyproxy
# Date created:		2008-06-12
# Whom:			Ashish Shukla <wahjava@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	foxyproxy
PORTVERSION=	2.19.1
DISTVERSIONSUFFIX=	-fx+sm+tb
CATEGORIES=	www

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Advanced proxy management tool

XPI_DISTNAME=	foxyproxy_standard
XPI_NUM=	2464
XPI_ID=		foxyproxy@eric.h.jung

post-extract:
	${FIND} ${WRKSRC} -type f -name '*.js' |${XARGS} ${SED} -i '' -e 's/[[:space:]]*$$//g'

pre-install:
	${FIND} ${WRKSRC} -type f -name '*.orig' |${XARGS} ${RM} -f

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
