# New ports collection makefile for:	chimera
# Version required:     2.0a11
# Date created:         24 Nov 1997
# Whom:                 Bruce Gingery <bgingery@gtcs.com>
#
# $Id: Makefile,v 1.15 1998/05/04 20:22:34 jseger Exp $
#

DISTNAME=	chimera-2.0a11
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.cs.unlv.edu/pub/chimera-alpha/

MAINTAINER=	bgingery@gtcs.com

LIB_DEPENDS=	jpeg\\.9\\.:${PORTSDIR}/graphics/jpeg \
		png\\.2\\.:${PORTSDIR}/graphics/png

USE_IMAKE=	yes

post-patch:
		${MV} ${WRKSRC}/Common.tmpl.dist ${WRKSRC}/Common.tmpl
		${CP} ${FILESDIR}/protopng.h ${WRKSRC}/image/
		ln -s ${WRKSRC}/chimera ${WRKSRC}/main

.include <bsd.port.mk>
