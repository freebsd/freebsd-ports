# New ports collection makefile for:   docproj
# Version required:    around June 1998
# Date created:        27 June 1998
# Whom:                Nik Clayton <nik@freebsd.org>
#
# $Id: Makefile,v 1.3 1998/07/07 12:18:27 nik Exp $
#

DISTNAME=	docproj
PKGNAME=	docproj-1.0
CATEGORIES=	textproc
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	nik@freebsd.org

# sgmlformat brings in almost everything except for the modular stylesheets
BUILD_DEPENDS=	instant:${PORTSDIR}/textproc/sgmlformat \
		${PREFIX}/share/sgml/docbook/dsssl/modular:${PORTSDIR}/textproc/dsssl-docbook-modular

EXTRACT_ONLY=	# empty
NO_BUILD=	yes

do-install:	# empty

.include <bsd.port.mk>
