# New ports collection makefile for:   htdig
# Version required:    3.0.8b2
# Date created:        18 August 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $Id: Makefile,v 1.3 1998/11/23 21:40:29 billf Exp $
#

DISTNAME=	htdig-3.1.0b2
PKGNAME=	htdig-3.1.0
CATEGORIES=	textproc
MASTER_SITES=	http://www.htdig.org/files/ \
		http://www.FreeBSD.org/~billf/

MAINTAINER=	billf@FreeBSD.org

Y2K=		http://www.htdig.org/FAQ.html#q1.7

GNU_CONFIGURE=	yes
BUILD_TARGET=	depends all

post-patch:

	${MV} ${WRKSRC}/CONFIG.in ${WRKSRC}/CONFIG.in.old
	${CAT} ${WRKSRC}/CONFIG.in.old | \
	${SED} -e 's#/opt/www/#${PREFIX}/www/#g' \
		-e 's#htdocs#data#g' \
		-e 's#/conf#/etc#' \
		-e 's#/common#/share/htdig#' \
		-e 's#/db#/share/htdig#' \
	>> ${WRKSRC}/CONFIG.in

.include <bsd.port.mk>
