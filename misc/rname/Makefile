# New ports collection makefile for:	rname
# Date created:		26 October 2000
# Whom:			roam@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	rname
PORTVERSION=	1.0
CATEGORIES=	misc
MASTER_SITES=	http://mail.orbitel.bg/~roam/devel/sys/rname/ \
		http://ringwraith.online.bg/~roam/devel/sys/rname/

MAINTAINER=	roam@FreeBSD.org

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_GMAKE=	yes

.if 		!defined(NOPORTDOCS)
INSTALL_TARGET=	install install-doc
.endif

.include <bsd.port.mk>
