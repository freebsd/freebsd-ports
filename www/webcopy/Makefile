# New ports collection makefile for:    webcopy
# Version required:     0.98b7
# Date created:         14 Sep 1996
# Whom:                 ache
#
# $FreeBSD$
#

# WWW site: http://www.inf.utfsm.cl/~vparada/webcopy.html

DISTNAME=       webcopy-0.98b7
CATEGORIES=     www
MASTER_SITES=   ftp://ftp.inf.utfsm.cl/pub/utfsm/perl/
DISTFILES=      webcopy.tgz

MAINTAINER=     ache@FreeBSD.org

NO_PACKAGE= "This program cannot be distributed if modified in any way"
NO_CDROM= "Don't sell for profit without written permission"
ALL_TARGET=

do-install:
	cd ${WRKSRC}; ${INSTALL_SCRIPT} webcopy ${PREFIX}/bin
	${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m 755 \
		${PREFIX}/share/doc/webcopy
	cd ${WRKSRC}; ${INSTALL_DATA} webcopy.html ${PREFIX}/share/doc/webcopy

.include <bsd.port.mk>
