# New ports collection makefile for:	xpi-foxyproxy
# Date created:		2008-06-12
# Whom:			Ashish Shukla <wahjava@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	foxyproxy
PORTVERSION=	4.1.1
DISTVERSIONSUFFIX=	-sm+tb+fx
CATEGORIES=	www

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Advanced proxy management tool

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

XPI_DISTNAME=	foxyproxy_standard
XPI_NUM=	2464
XPI_ID=		foxyproxy@eric.h.jung

xpi-post-extract:
	@${FIND} ${WRKSRC} -type f -name '*.js' |${XARGS} ${SED} -i '' -e 's/[[:space:]]*$$//g'

pre-install:
	@${FIND} ${WRKSRC} -type f -name '*.orig' -delete
	@${FIND} ${WRKSRC} -type f -name '*.bak' -delete

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
