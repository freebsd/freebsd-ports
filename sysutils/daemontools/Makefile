# New ports collection makefile for:	daemontools
# Date created:		09 June 1998
# Whom:			Dom Mitchell <dom@myrddin.demon.co.uk>
#
# $FreeBSD$
#

PORTNAME=	daemontools
PORTVERSION=	0.70
CATEGORIES=	sysutils
MASTER_SITES=	http://cr.yp.to/daemontools/ \
		ftp://cr.yp.to/daemontools/

MAINTAINER=	nbm@FreeBSD.org

NO_PACKAGE=	"Unsure of djb\'s license"

ALL_TARGET=	it
INSTALL_TARGET=	setup check

SAMPLERC=	svscan.sh.sample
SERVICEDIR?=	/var/service/

post-patch:
	@echo "${CC} ${CFLAGS}" > ${WRKSRC}/conf-cc
	@echo "${CC} -s" > ${WRKSRC}/conf-ld
	@echo "${PREFIX}" > ${WRKSRC}/conf-home

post-build:
	@${SED} "s!/usr/local/!${PREFIX}/!;s!/var/service!${SERVICEDIR}!g" \
		${FILESDIR}/${SAMPLERC} > ${WRKDIR}/${SAMPLERC}

post-install:
	@${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m 755 \
		${PREFIX}/share/examples/${PORTNAME}
	@${INSTALL_DATA} ${WRKDIR}/${SAMPLERC} \
		${PREFIX}/share/examples/${PORTNAME}

.include <bsd.port.mk>
