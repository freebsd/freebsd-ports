# New ports collection makefile for:	tkxanim
# Date created:				24 October 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

PORTNAME=	tkxanim
PORTVERSION=	0.43
PORTREVISION=	3
CATEGORIES=	multimedia tk
MASTER_SITES=	http://freshmeat.net/redir/tkxanim/10652/url_tgz/ \
		http://freebsd.unixfreunde.de/sources/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tcl/Tk frontend to xanim

DEPRECATED=     Upstream has disapear and dstfile is no more available
EXPIRATION_DATE=        2011-05-01

RUN_DEPENDS=	xanim:${PORTSDIR}/multimedia/xanim
USE_TK_RUN=	yes

WRKSRC=		${WRKDIR}/Tkxanim

do-build:
		@${MV} ${WRKSRC}/tkxanim ${WRKSRC}/tkxanim.orig
		@${SED} -e 's|CHANGEME|${PREFIX}|' \
		    < ${WRKSRC}/tkxanim.orig > ${WRKSRC}/tkxanim

do-install:
		${INSTALL_SCRIPT} ${WRKSRC}/tkxanim ${PREFIX}/bin
		-${MKDIR} ${PREFIX}/share/icons
		${INSTALL_DATA} ${WRKSRC}/tkxanim.gif ${PREFIX}/share/icons

.include <bsd.port.mk>
