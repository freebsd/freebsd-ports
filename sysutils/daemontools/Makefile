# New ports collection makefile for:	daemontools
# Date created:		09 June 1998
# Whom:			Dom Mitchell <dom@myrddin.demon.co.uk>
#
# $FreeBSD$
#

PORTNAME=	daemontools
PORTVERSION=	0.76
CATEGORIES=	sysutils
MASTER_SITES=	http://cr.yp.to/daemontools/ \
		ftp://cr.yp.to/daemontools/

MAINTAINER=	roam@FreeBSD.org

WRKSRC=		${WRKDIR}/admin/${DISTNAME}/src
NO_PACKAGE=	"Unsure of djb\'s license"

ALL_TARGET=	it
INSTALL_TARGET=	setup check

SAMPLERC=	svscan.sh.sample
SERVICEDIR?=	/var/service/

post-patch:
	@echo "${CC} ${CFLAGS}" > ${WRKSRC}/conf-cc
	@echo "${CC} ${STRIP}" > ${WRKSRC}/conf-ld

post-build:
	@${SED} "s!/usr/local/!${PREFIX}/!;s!/var/service!${SERVICEDIR}!g" \
		${FILESDIR}/${SAMPLERC} > ${WRKDIR}/${SAMPLERC}

do-install:
	(while read cmd; do \
		if file ${WRKSRC}/$$cmd | ${GREP} -q "shell script"; then \
			${INSTALL_SCRIPT} ${WRKSRC}/$$cmd ${PREFIX}/bin; \
		else \
			${INSTALL_PROGRAM} ${WRKSRC}/$$cmd ${PREFIX}/bin; \
		fi \
	done) < ${WRKSRC}/../package/commands

post-install:
	@${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m 755 \
		${PREFIX}/share/examples/${PORTNAME}
	@${INSTALL_DATA} ${WRKDIR}/${SAMPLERC} \
		${PREFIX}/share/examples/${PORTNAME}

.include <bsd.port.mk>
