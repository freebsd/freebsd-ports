# New ports collection makefile for:	MHonArc
# Version required:			2.1
# Date created:				18 June 1997
# Whom:					koshy@india.hp.com
#
# $Id$
#

DISTNAME=	MHonArc2.1
PKGNAME=	mhonarc-2.1
CATEGORIES=	www mail
MASTER_SITES=	http://www.oac.uci.edu/indiv/ehood/tar/ \
		ftp://hhobel.phl.univie.ac.at/MHonArc/

MAINTAINER=	ports@freebsd.org

INSTALL_TARGET=	install-batch

pre-install:
		${MKDIR} ${PREFIX}/lib/MHonArc
		${MKDIR} ${PREFIX}/lib/MHonArc/doc/resources

.include <bsd.port.mk>

