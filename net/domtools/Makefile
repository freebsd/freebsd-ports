# New ports collection makefile for:	domtools
# Version required:			1.4.0
# Date created:				12 Jun 1999
# Whom:					alexp
#
# $FreeBSD$
#

DISTNAME=       domtools${VERSION}
PKGNAME= 	domtools-${VERSION}
CATEGORIES=     net
MASTER_SITES=   http://www.domtools.com/pub/

MAINTAINER=     veers@disturbed.net

USE_PERL5= 	YES

NO_BUILD=	YES
WRKSRC=		${WRKDIR}/domtools${VERSION}/
VERSION=	1.4.0

# XXX - patches/patch-aa modifies Makefile
# and so does the post-patch target

post-patch:

	${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.old
	${SED} -e 's#/usr/bin/perl#${PERL5}#' \
	< ${WRKSRC}/Makefile.old > ${WRKSRC}/Makefile

post-install:

	${MKDIR} ${PREFIX}/domtools/lib/zonecache

.include <bsd.port.mk>
