# New ports collection makefile for:   htdig
# Version required:    3.1.0b4
# Date created:        18 August 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $Id: Makefile,v 1.5 1999/01/20 20:21:32 billf Exp $
#

DISTNAME=	htdig-3.1.0b4
PKGNAME=	htdig-3.1.0
CATEGORIES=	textproc www
MASTER_SITES=	http://www.htdig.org/files/ \
		ftp://ftp.medasys-digital-systems.fr/mirror/htdig/files/ \
		ftp://ftp.htdig.org/pub/htdig/ \
		http://www.FreeBSD.org/~billf/

MAINTAINER=	billf@FreeBSD.org

Y2K=		http://www.htdig.org/FAQ.html#q1.7

GNU_CONFIGURE=	yes
BUILD_TARGET=	depends all

post-patch:

	${MV} ${WRKSRC}/CONFIG.in ${WRKSRC}/CONFIG.in.old
	${SED} -e 's#/opt/www/#${PREFIX}/www/#g' \
		-e 's#htdocs#data#g' \
		-e 's#/conf#/etc#' \
		-e 's#/common#/share/htdig#' \
		-e 's#/db#/share/htdig#' \
	${WRKSRC}/CONFIG.in.old >> ${WRKSRC}/CONFIG.in

.include <bsd.port.mk>
