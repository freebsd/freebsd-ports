# New ports collection makefile for: dict
# Date created:         11 October 1997
# Whom:                 wosch
#
# $FreeBSD$
#

PORTNAME=	momspider
PORTVERSION=	1.00
CATEGORIES=	www
MASTER_SITES=   ftp://www.ics.uci.edu/pub/websoft/libwww-perl/ \
		ftp://www.ics.uci.edu/pub/websoft/MOMspider/ \
		http://www.de.freebsd.org/~wosch/src/
DISTNAME=	MOMspider-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} libwww-perl-0.40.tar.gz

MAINTAINER=	wosch@FreeBSD.org

NO_BUILD=	yes
momdir=		${PREFIX}/momspider
wwwdir=		libwww-perl-0.40

do-install:
	${MKDIR} ${momdir}/${wwwdir}
	${CP} -r ${WRKSRC}/* ${momdir}
	${RM} -rf ${WRKSRC}/../${wwwdir}/RCS
	${CP} -r ${WRKSRC}/../${wwwdir} ${momdir}
	${INSTALL} -c -o ${BINOWN} -g ${BINGRP} -m ${BINMODE} \
	    ${FILESDIR}/momspider.sh ${PREFIX}/bin/momspider

.include <bsd.port.mk>
