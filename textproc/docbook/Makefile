# New ports collection makefile for:   docbook
# Version required:    N/A
# Date created:        7 April 1999
# Whom:                Nik Clayton <nik@freebsd.org>
#
# Based heavily on work by jfieber
#
# $Id: Makefile,v 1.5 1999/04/14 22:36:01 nik Exp $
#

DISTNAME=       docbook
PKGNAME=        docbook-1.0
CATEGORIES=     textproc
MASTER_SITES=   # empty
DISTFILES=      # empty

MAINTAINER=     nik@freebsd.org

BUILD_DEPENDS=  ${PREFIX}/share/sgml/docbook/2.4.1:${PORTSDIR}/textproc/docbook-241 \
		${PREFIX}/share/sgml/docbook/3.0:${PORTSDIR}/textproc/docbook-300 \
		${PREFIX}/share/sgml/docbook/3.1:${PORTSDIR}/textproc/docbook-310

EXTRACT_ONLY=   # empty
NO_BUILD=       yes

do-install:     # empty

post-install:
	${ECHO} 'CATALOG "2.4.1/catalog"' >  ${PREFIX}/share/sgml/docbook/catalog
	${ECHO} 'CATALOG "3.0/catalog"'   >> ${PREFIX}/share/sgml/docbook/catalog
	${ECHO} 'CATALOG "3.1/catalog"'   >> ${PREFIX}/share/sgml/docbook/catalog

.include <bsd.port.mk>
