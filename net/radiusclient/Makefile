# New ports collection makefile for:   radiusclient
# Version required:    0.3
# Date created:        Wed Nov  4 08:48:08 EST 1998
# Whom:                maurice
#
# $Id$
#

DISTNAME=      radiusclient-0.3
CATEGORIES=    net
MASTER_SITES=  ftp://ftp.cityline.net/pub/radiusclient/

MAINTAINER=    maurice@serc.rmit.edu.au

USE_GMAKE=     yes
GNU_CONFIGURE= yes
CONFIGURE_ARGS=	--enable-shared=NO

post-configure:
	(cd ${WRKSRC}; ./ltconfig --disable-shared ltmain.sh)

.include <bsd.port.mk>
