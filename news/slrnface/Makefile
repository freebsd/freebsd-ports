# New ports collection makefile for:   slrnface
# Date created:        10 April 2002
# Whom:                Oliver Braun <obraun@informatik.unibw-muenchen.de>
#
# $FreeBSD$
#

PORTNAME=	slrnface
PORTVERSION=	1.2
CATEGORIES=	news
MASTER_SITES=	http://fly.cc.fer.hr/~dave/slrnface/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	compface:${PORTSDIR}/mail/faces

ALL_TARGET=	slrnface

USE_XLIB=	yes
USE_GMAKE=	yes

post-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/slrnface ${PREFIX}/bin
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/slrnface.sl ${EXAMPLESDIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
