# New ports collection makefile for:   radiusclient
# Version required:    0.3
# Date created:        Wed Nov  4 08:48:08 EST 1998
# Whom:                maurice
#
# $Id: Makefile,v 1.1.1.1 1998/11/04 03:17:53 jkoshy Exp $
#

DISTNAME=	radiusclient-0.3
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.cityline.net/pub/radiusclient/

MAINTAINER=	maurice@serc.rmit.edu.au

BUILD_DEPENDS=	/nonexistent:${PORTSDIR}/devel/libtool:patch

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

pre-configure:
	${CP} ${WRKDIRPREFIX}${PORTSDIR}/devel/libtool/work/libtool-1.2/ltconfig ${WRKSRC}
	${CP} ${WRKDIRPREFIX}${PORTSDIR}/devel/libtool/work/libtool-1.2/ltmain.sh ${WRKSRC}

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
