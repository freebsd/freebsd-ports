# New ports collection makefile for:	xpi-foxyproxy
# Date created:		2008-06-12
# Whom:			Ashish Shukla <wahjava@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	foxyproxy
PORTVERSION=	2.21.3
DISTVERSIONSUFFIX=	-fx+sm+tb
CATEGORIES=	www

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Advanced proxy management tool

XPI_DISTNAME=	foxyproxy_standard
XPI_NUM=	2464
XPI_ID=		foxyproxy@eric.h.jung

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

post-extract:
	@${FIND} ${WRKSRC} -type f -name '*.js' |${XARGS} ${SED} -i '' -e 's/[[:space:]]*$$//g'
	@${MV} ${WRKSRC}/LICENSE ${WRKSRC}/COPYING
	@${GREP} -Rl LICENSE ${WRKSRC} |${XARGS} ${REINPLACE_CMD} -e s/LICENSE/COPYING/g

pre-install:
	@${FIND} ${WRKSRC} -type f -name '*.orig' |${XARGS} ${RM} -f
	@${FIND} ${WRKSRC} -type f -name '*.bak' |${XARGS} ${RM} -f

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
