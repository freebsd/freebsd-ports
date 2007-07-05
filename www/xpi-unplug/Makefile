# New ports collection makefile for:	xpi-unplug
# Date created:			2006/05/06
# Whom:				chinsan <chinsan.tw@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	unplug
DISTVERSION=	1.6.06
DISTVERSIONSUFFIX=	-fx
CATEGORIES=	www

MAINTAINER=	chinsan@FreeBSD.org
COMMENT=	Converts embedded media to html links

XPI_ID=		unplug@compunach
XPI_NUM=	2254

post-extract:
	@${FIND} ${WRKSRC} -type d -name CVS|${XARGS} ${RM} -rf

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
