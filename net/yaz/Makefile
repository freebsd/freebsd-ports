# New ports collection makefile for:	yaz
# Date created:		16 Sep 2000
# Whom:			Dmitry Sivachenko <dima@Chg.RU>
#
# $FreeBSD$
#

PORTNAME=	yaz
PORTVERSION=	1.6
CATEGORIES=	net
MASTER_SITES=	http://ftp.indexdata.dk/pub/yaz/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	jeh

MAINTAINER=	demon@FreeBSD.org

GNU_CONFIGURE=	yes

post-install:
.if !defined(NOPORTDOCS)
		@(cd ${WRKSRC}/doc; ${MAKE} install)
.endif

.include <bsd.port.mk>
