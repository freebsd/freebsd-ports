# New ports collection makefile for:   docproj
# Version required:    around June 1998
# Date created:        27 June 1998
# Whom:                Nik Clayton <nik@freebsd.org>
#
# $Id: Makefile,v 1.5 1998/12/18 10:55:54 jkh Exp $
#

DISTNAME=	docproj
PKGNAME=	docproj-1.0
CATEGORIES=	textproc
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	nik@freebsd.org

RUN_DEPENDS=	instant:${PORTSDIR}/textproc/sgmlformat \
		${PREFIX}/share/sgml/docbook/dsssl/modular:${PORTSDIR}/textproc/dsssl-docbook-modular \
		tidy:${PORTSDIR}/www/tidy \
		${PREFIX}/share/sgml/html/catalog:${PORTSDIR}/textproc/html

EXTRACT_ONLY=	# empty
NO_BUILD=	yes

do-install:	# empty

.include <bsd.port.mk>
