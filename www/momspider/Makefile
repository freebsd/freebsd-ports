# Created by:                 wosch
# $FreeBSD$

PORTNAME=	momspider
PORTVERSION=	1.00
CATEGORIES=	www
MASTER_SITES=	http://wolfram.schneider.org/src/
DISTNAME=	MOMspider-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} libwww-perl-0.40.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	WWW Spider for multi-owner maintenance

DEPRECATED=	No more public distfiles
EXPIRATION_DATE=	2012-11-26

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
