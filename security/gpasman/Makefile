# New ports collection makefile for:	gpasman
# Version required:		1.3.0
# Date created:			Mon Mai 10 1999
# Whom:				domi@saargate.de
#
# $FreeBSD$
#

DISTNAME=	gpasman-1.3.0
CATEGORIES=	security
MASTER_SITES=	http://gpasman.nl.linux.org/

MAINTAINER=	domi@saargate.de

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

USE_GMAKE=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes

do-install:
	 ${INSTALL_PROGRAM} ${WRKSRC}/src/gpasman ${PREFIX}/bin

.include <bsd.port.mk>
