# New ports collection makefile for:    dvips2ascii
# Date created:         7 Aug 1997
# Whom:                 eserte@cs.tu-berlin.de
#
# $FreeBSD$
#

PORTNAME=	dvips2ascii
PORTVERSION=	1.3
CATEGORIES=	print
MASTER_SITES=	http://www.de.freebsd.org/~eserte/distfiles/

MAINTAINER=	eserte@cs.tu-berlin.de

do-build:
	${MV} ${WRKSRC}/dvips2ascii ${WRKSRC}/dvips2ascii.orig
	${SED} -e 's;#!.*perl;#!${PERL};' \
	    < ${WRKSRC}/dvips2ascii.orig > ${WRKSRC}/dvips2ascii

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/dvips2ascii ${PREFIX}/bin

.include <bsd.port.mk>
