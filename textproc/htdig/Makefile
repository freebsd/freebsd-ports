# New ports collection makefile for:   htdig
# Version required:    3.0.8b2
# Date created:        18 August 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $Id: $
#

DISTNAME=	htdig-3.1.0b2
PKGNAME=	htdig-3.1.0
CATEGORIES=	textproc
MASTER_SITES=	http://www.htdig.org/files/ \
		http://www.FreeBSD.org/~billf/

MAINTAINER=	billf@FreeBSD.org

GNU_CONFIGURE=	yes
BUILD_TARGET=	depends all

post-patch:

	${MV} ${WRKSRC}/CONFIG.in ${WRKSRC}/CONFIG.in.old
	${CAT} ${WRKSRC}/CONFIG.in.old | \
	${SED} -e 's#/opt/www/#${PREFIX}/www/#g' | \
	${SED} -e 's#htdocs#data#g' >> ${WRKSRC}/CONFIG.in

.include <bsd.port.mk>
