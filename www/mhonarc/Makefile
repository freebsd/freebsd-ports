# New ports collection makefile for:	MHonArc
# Version required:			2.1
# Date created:				18 June 1997
# Whom:					koshy@india.hp.com
#
# $Id: Makefile,v 1.2 1997/07/01 17:41:02 jfitz Exp $
#

DISTNAME=	MHonArc2.2.0
PKGNAME=	mhonarc-2.2.0
CATEGORIES=	www mail
MASTER_SITES=	http://www.oac.uci.edu/indiv/ehood/tar/ \
		ftp://hhobel.phl.univie.ac.at/MHonArc/

MAINTAINER=	koshy@india.hp.com

USE_PERL5=	YES

INSTALL_TARGET=	install-batch

pre-install:
		${MKDIR} ${PREFIX}/lib/MHonArc
		${MKDIR} ${PREFIX}/lib/MHonArc/doc/resources

.include <bsd.port.mk>
