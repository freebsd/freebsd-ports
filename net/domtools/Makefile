# New ports collection makefile for:	domtools
# Date created:				12 Jun 1999
# Whom:					alexp
#
# $FreeBSD$
#

PORTNAME=	domtools
PORTVERSION=	1.4.0
CATEGORIES=     net
MASTER_SITES=   http://www.domtools.com/pub/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=     veers@disturbed.net

USE_PERL5= 	YES

NO_BUILD=	YES
WRKSRC=		${WRKDIR}/domtools${PORTVERSION}/

# XXX - patches/patch-aa modifies Makefile
# and so does the post-patch target

post-patch:

	${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.old
	${SED} -e 's#/usr/bin/perl#${PERL5}#' \
	< ${WRKSRC}/Makefile.old > ${WRKSRC}/Makefile

post-install:

	${MKDIR} ${PREFIX}/domtools/lib/zonecache

.include <bsd.port.mk>
