# New ports collection makefile for:	chimera
# Version required:     2.0a11
# Date created:         24 Nov 1997
# Whom:                 Bruce Gingery <bgingery@gtcs.com>
#
# $Id: Makefile,v 1.12 1997/11/26 07:53:32 tg Exp $
#

DISTNAME=	chimera-2.0a11
CATEGORIES=	www x11
MASTER_SITES=	ftp://ftp.cs.unlv.edu/pub/chimera-alpha/

MAINTAINER=	bgingery@gtcs.com

LIB_DEPENDS=	jpeg\\.[67]\\.:${PORTSDIR}/graphics/jpeg \
		png\\.2\\.:${PORTSDIR}/graphics/png

USE_IMAKE=	yes

post-patch:
		${MV} ${WRKSRC}/Common.tmpl.dist ${WRKSRC}/Common.tmpl
		${CP} ${FILESDIR}/protopng.h ${WRKSRC}/image/
		ln -s ${WRKSRC}/chimera ${WRKSRC}/main

.include <bsd.port.mk>
