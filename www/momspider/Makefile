# New ports collection makefile for: dict
# Version required:     1.00
# Date created:         11 October 1997
# Whom:                 wosch
#
# $Id: Makefile,v 1.1.1.1 1997/10/11 17:58:55 wosch Exp $

DISTNAME=       MOMspider-1.00
CATEGORIES=	www
MASTER_SITES=   ftp://www.ics.uci.edu/pub/websoft/libwww-perl/ \
		ftp://www.ics.uci.edu/pub/websoft/MOMspider/ \
		http://www.freebsd.org/~wosch/src/
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
