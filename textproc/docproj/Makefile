# New ports collection makefile for:   docproj
# Version required:    around June 1998
# Date created:        27 June 1998
# Whom:                Nik Clayton <nik@freebsd.org>
#
# $Id$
#

DISTNAME=	docproj
CATEGORIES=	textproc
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	nik@freebsd.org

# sgmlformat brings in almost everything except for the modular stylesheets
RUN_DEPENDS=	instant:${PORTSDIR}/textproc/sgmlformat \
		${PREFIX}/share/sgml/docbook/dsssl/modular:${PORTSDIR}/textproc/dsssl-docbook-modular

EXTRACT_ONLY=	# empty
NO_PATCH=	yes
NO_BUILD=	yes

do-install:	# empty

.include <bsd.port.mk>
