# New ports collection makefile for:   htdig
# Version required:    3.1.1
# Date created:        18 August 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $Id: Makefile,v 1.6 1999/02/09 15:08:31 billf Exp $
#

DISTNAME=	htdig-3.1.1
CATEGORIES=	textproc www
MASTER_SITES=	http://www.htdig.org/files/ \
		ftp://ftp.ntua.gr/pub/www/htdig/ \
		ftp://ftp.htdig.org/pub/htdig/ \
		http://www.FreeBSD.org/~billf/

MAINTAINER=	billf@FreeBSD.org

Y2K=		http://www.htdig.org/FAQ.html#q1.7

GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --with-cgi-bin-dir=${PREFIX}/www/cgi-bin \
		--with-image-dir=${PREFIX}/www/icons \
		--with-search-dir=${PREFIX}/www/data
BUILD_TARGET=	depends all

post-patch:

	${MV} ${WRKSRC}/CONFIG.in ${WRKSRC}/CONFIG.in.old
	${SED} -e 's#htdocs#data#g' \
		-e 's#/conf#/etc#' \
		-e 's#/common#/share/htdig#' \
		-e 's#/db#/share/htdig#' \
	${WRKSRC}/CONFIG.in.old >> ${WRKSRC}/CONFIG.in

.include <bsd.port.mk>
