# New ports collection makefile for:	icqnix
# Version required:	b1
# Date created:		27 Aug 1999
# Whom:			Yin-Jieh Chen <yinjieh@csie.nctu.edu.tw>
#
# $FreeBSD$
#

DISTNAME=	icqnix-beta1
PKGNAME=	icqnix-b1
CATEGORIES=	net
MASTER_SITES=	http://icqnix.linuxbox.com/

MAINTAINER=	yinjieh@csie.nctu.edu.tw

RUN_DEPENDS=	esdplay:${PORTSDIR}/audio/esound

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_QT=		yes

post-install:
	@strip ${PREFIX}/bin/icqnix
	@strip ${PREFIX}/bin/icqnix.install

.include <bsd.port.mk>
