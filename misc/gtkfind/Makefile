# New ports collection makefile for:   gtkfind
# Version required:    0.9
# Date created:        28 Sept 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $Id: $
#

DISTNAME=	gtkfind-0.9
CATEGORIES=	misc
MASTER_SITES=	http://www.oz.net/~mattg/

MAINTAINER=	billf@FreeBSD.org

LIB_DEPENDS=	gtk.1.6:${PORTSDIR}/x11-toolkits/gtk

USE_GMAKE=	yes
ALL_TARGET=

MAN1=		gtkfind.1

post-patch:

	${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.pre_sed
	${CAT} ${WRKSRC}/Makefile.pre_sed | \
	${SED} -e 's#/usr/local#${PREFIX}#g' >> ${WRKSRC}/Makefile

.include <bsd.port.mk>
