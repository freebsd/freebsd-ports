# ex:ts=8
# New ports collection makefile for:	Crank
# Date created:			Apr 18, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	crank
PORTVERSION=	0.1.2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ijliao@FreeBSD.org

USE_GTK=	yes
USE_GMAKE=	yes

post-patch:
.for file in Makefile plugin-src/Makefile
	@${PERL} -pi -e "s,gtk-config,${GTK_CONFIG},g" ${WRKSRC}/${file}
.endfor
	@${PERL} -pi -e "s,plugins,${PREFIX}/lib/crank,g" ${WRKSRC}/crank.h
	@${PERL} -pi -e "s, -g , ,g" ${WRKSRC}/plugin-src/Makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/crank ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/lib/crank
	@${CP} ${WRKSRC}/plugin-src/*.so ${PREFIX}/lib/crank

.include <bsd.port.mk>
